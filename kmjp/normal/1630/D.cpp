#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
int N,M;
int A[1010101],B[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		scanf("%d",&M);
		FOR(i,N) scanf("%d",&A[i]);
		int G=0;
		FOR(i,M) {
			scanf("%d",&B[i]);
			G=__gcd(G,B[i]);
		}
		
		ll ret=0;
		if(G==1) {
			FOR(i,N) ret+=abs(A[i]);
		}
		else {
			ret=-1LL<<60;
			FOR(y,2) {
				ll sum=0;
				FOR(i,G) {
					vector<ll> p,m;
					for(x=i;x<N;x+=G) {
						if(A[x]>=0) p.push_back(A[x]);
						else m.push_back(-A[x]);
					}
					sort(ALL(p));
					sort(ALL(m));
					
					if(y==0) {
						if(m.size()%2) {
							if(p.size()&&p[0]<m[0]) {
								p[0]=-p[0];
							}
							else {
								m[0]=-m[0];
							}
						}
					}
					else {
						if(m.size()%2==0) {
							if(p.size()&&m.size()) {
								if(p[0]<m[0]) p[0]=-p[0];
								else m[0]=-m[0];
							}
							else if(p.size()) p[0]=-p[0];
							else m[0]=-m[0];
						}
					}
					FORR(a,p) sum+=a;
					FORR(a,m) sum+=a;
				}
				ret=max(ret,sum);
			}
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}