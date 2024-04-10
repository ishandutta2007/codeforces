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

int N,M;
int A[202020];
int B[302020];
const int DI=1000;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,18> bt[400];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,N) {
		scanf("%d",&x);
		A[x]=i;
	}
	FOR(i,N) {
		scanf("%d",&x);
		B[i]=A[x];
		bt[i/DI].add(B[i],1);
	}
	
	
	while(M--) {
		scanf("%d",&i);
		if(i==1) {
			int LA,RA,LB,RB;
			scanf("%d%d%d%d",&LA,&RA,&LB,&RB);
			LA--;
			RA--;
			LB--;
			int num=0;
			while(LB<RB && LB%DI) {
				if(B[LB]>=LA && B[LB]<=RA) num++;
				LB++;
			}
			while(LB<RB && RB%DI) {
				RB--;
				if(B[RB]>=LA && B[RB]<=RA) num++;
			}
			while(LB<RB) {
				num+=bt[LB/DI](RA)-bt[LB/DI](LA-1);
				LB+=DI;
			}
			cout<<num<<endl;
			
		}
		else {
			scanf("%d%d",&x,&y);
			x--,y--;
			bt[x/DI].add(B[x],-1);
			bt[y/DI].add(B[y],-1);
			swap(B[x],B[y]);
			bt[x/DI].add(B[x],1);
			bt[y/DI].add(B[y],1);
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}