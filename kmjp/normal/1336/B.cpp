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

int T;
int N[3];
int A[3][101010];
vector<pair<int,int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		V.clear();
		scanf("%d%d%d",&N[0],&N[1],&N[2]);
		FOR(i,3) {
			FOR(j,N[i]) {
				scanf("%d",&x);
				A[i][j]=x;
				V.push_back({x,i});
			}
			sort(A[i],A[i]+N[i]);
		}
		sort(ALL(V));
		ll mi=1LL<<62;
		ll t[3]={-1LL<<30,-1LL<<30,-1LL<<30};
		FORR(e,V) {
			t[e.second]=e.first;
			if(t[0]<0 || t[1]<0 || t[2]<0) continue;
			FOR(x,3) FOR(y,3) if(x!=y) {
				ll tar=(t[x]+t[y])/2;
				i=3-x-y;
				j=lower_bound(A[i],A[i]+N[i],tar)-A[i];
				for(k=max(0,j-1);k<=min(N[i]-1,j+1);k++) {
					ll v=A[i][k];
					mi=min(mi,(t[x]-t[y])*(t[x]-t[y])+(t[x]-v)*(t[x]-v)+(t[y]-v)*(t[y]-v));
				}
			}
		}
		cout<<mi<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}