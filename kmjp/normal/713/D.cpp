#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V,int NV> class RMQ_2D {
private:
	V table[NV][NV][1<<NV][1<<NV];
	int LG[1<<NV];
	int NV2;
public:
	static V const def=-1<<30;
	V comp(V l,V r){ return max(l,r);};
	RMQ_2D() {
		int i,j,x,y;
		NV2=1<<NV;
		for(i=2;i<	NV2;i++) LG[i]=LG[i/2]+1;
		FOR(i,NV) FOR(j,NV) FOR(x,NV2) FOR(y,NV2) table[i][j][x][y]=def;
	}
	void set(int x,int y,V v){ table[0][0][x][y]=v;}
	void build() {
		int i,j,x,y;
		FOR(i,NV) FOR(j,NV) FOR(x,NV2) FOR(y,NV2) {
			if(i<NV-1) table[i+1][j][x][y]=comp(table[i][j][x][y],(x+(1<<i)<NV2)?table[i][j][x+(1<<i)][y]:def);
			if(j<NV-1) table[i][j+1][x][y]=comp(table[i][j][x][y],(y+(1<<j)<NV2)?table[i][j][x][y+(1<<j)]:def);
		}
	}
	V query(int L,int R,int T,int B) { //[L,R), [T,B)
		L=max(0,L), R=min(R,NV2), T=max(0,T), B=min(B,NV2);
		if(R<=L || B<=T) return def;
		int WL=LG[R-L],HL=LG[B-T];
		return comp(comp(table[WL][HL][L][T],table[WL][HL][R-(1<<WL)][T]),
			comp(table[WL][HL][L][B-(1<<HL)],table[WL][HL][R-(1<<WL)][B-(1<<HL)]));
	}
	
};

RMQ_2D<int,10> rmq;
int H,W,Q;
int A[1010][1010];
int S[2010][2010];
int T[1010][1010];

int yes(int y,int x,int t) {
	return (S[y+t][x+t]-S[y+t][x]-S[y][x+t]+S[y][x])==t*t;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&H,&W);
	FOR(y,H) FOR(x,W) {
		scanf("%d",&A[y][x]);
		S[y+1][x+1]=S[y+1][x]+S[y][x+1]-S[y][x]+A[y][x];
	}
	FOR(y,H) FOR(x,W) {
		if(A[y][x]) {
			T[y][x]=1;
			if(y&&x) T[y][x]=max(T[y][x],T[y-1][x-1]-1);
			while(yes(y,x,T[y][x]+1)) T[y][x]++;
		}
		rmq.set(x,y,T[y][x]);
	}
	rmq.build();
	
	scanf("%d",&Q);
	while(Q--) {
		int L,R,T,B;
		scanf("%d%d%d%d",&L,&T,&R,&B);
		L--,T--;
		x=0;
		for(i=9;i>=0;i--) {
			y=x+(1<<i);
			if(rmq.query(T,B-(y-1),L,R-(y-1))>=y) x=y;
		}
		_P("%d\n",x);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}