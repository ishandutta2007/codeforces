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

int H,W,Q;
string S[505];
int A[4][505][505];
int ok[505][505];

template<class V,int NV> class RMQ_2D {
private:
	V table[NV][NV][1<<NV][1<<NV];
	int LG[1<<NV];
	int NV2;
public:
	static V const def=0;
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

RMQ_2D<int,9> rmq;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&H,&W,&Q);
	FOR(y,H) {
		char buf[510];
		scanf("%s",buf);
		S[y]=buf;
		FOR(x,W) {
			if(S[y][x]=='R') A[0][y+1][x+1]++;
			if(S[y][x]=='G') A[1][y+1][x+1]++;
			if(S[y][x]=='Y') A[2][y+1][x+1]++;
			if(S[y][x]=='B') A[3][y+1][x+1]++;
			FOR(i,4) A[i][y+1][x+1]+=A[i][y][x+1]+A[i][y+1][x]-A[i][y][x];
		}
	}
	FOR(y,H-1) FOR(x,W-1) if(S[y][x]=='R' && S[y][x+1]=='G' && S[y+1][x]=='Y' && S[y+1][x+1]=='B') {
		i=1;
		while(y>=i && x>=i && x+i+1<W && y+i+1<H) {
			if(A[0][y+1][x+1]-A[0][y-i][x+1]-A[0][y+1][x-i]+A[0][y-i][x-i]!=(i+1)*(i+1)) break;
			if(A[1][y+1][x+1+i+1]-A[1][y-i][x+1+i+1]-A[1][y+1][x-i+i+1]+A[1][y-i][x-i+i+1]!=(i+1)*(i+1)) break;
			if(A[2][y+1+i+1][x+1]-A[2][y-i+i+1][x+1]-A[2][y+1+i+1][x-i]+A[2][y-i+i+1][x-i]!=(i+1)*(i+1)) break;
			if(A[3][y+1+i+1][x+1+i+1]-A[3][y-i+i+1][x+1+i+1]-A[3][y+1+i+1][x-i+i+1]+A[3][y-i+i+1][x-i+i+1]!=(i+1)*(i+1)) break;
			i++;
		}
		ok[y][x]=i;
		rmq.set(y,x,i);
	}
	rmq.build();
	
	while(Q--) {
		int R1,C1,R2,C2;
		scanf("%d%d%d%d",&R1,&C1,&R2,&C2);
		R1--;
		C1--;
		R2-=2;
		C2-=2;
		int ma=0;
		int mad=min(R2-R1+2,C2-C1+2)/2;
		for(i=9;i>=0;i--) if(ma+(1<<i)<=mad) {
			y=ma+(1<<i);
			x=rmq.query(R1+y-1,R2-y+2,C1+y-1,C2-y+2);
			if(x>=y) ma=y;
		}
		
		_P("%d\n",4*ma*ma);
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}