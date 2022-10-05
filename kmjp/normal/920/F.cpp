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

int table[1010101];
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

int N,M;
int A[303030];
char buf[10];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=1000000;i++) {
		for(j=i;j<=1000000;j+=i) table[j]++;
	}
	
	scanf("%d%d",&N,&M);
	set<int> S;
	FOR(i,N) {
		S.insert(i+1);
		scanf("%d",&A[i+1]);
		bt.add(i+1,A[i+1]);
	}
	S.insert(N+1);
	while(M--) {
		int L,R;
		scanf("%d%d%d",&x,&L,&R);
		if(x==1) {
			x=L;
			while(x<=R) {
				auto it=S.lower_bound(x);
				x=*it;
				if(x>R) break;
				
				if(A[x]==table[A[x]]) {
					S.erase(it);
				}
				else {
					bt.add(x,-(A[x]-table[A[x]]));
					A[x]=table[A[x]];
				}
				x++;
			}
		}
		else {
			cout<<(bt(R)-bt(L-1))<<endl;
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}