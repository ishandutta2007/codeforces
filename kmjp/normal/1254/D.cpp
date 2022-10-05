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

int N,Q;
vector<int> E[202020];
vector<pair<int,int>> CL[202020];
int C[202020];
int L[202020],R[202020];
int id=0;
ll V[202020];
ll A[202020];

set<int> add;
const ll mo=998244353;
ll TP[202020];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int dfs(int cur,int pre) {
	C[cur]=1;
	L[cur]=id++;
	FORR(e,E[cur]) if(e!=pre) {
		C[cur]+=dfs(e,cur);
		CL[cur].push_back({R[e]-1,e});
	}
	R[cur]=id;
	return C[cur];
}

ll prop(int cur,int pre) {
	if(A[cur]) TP[cur]=C[cur]*A[cur];
	FORR(e,E[cur]) if(e!=pre) TP[cur]+=prop(e,cur);
	TP[cur]%=mo;
	return TP[cur];
}
void prop2(int cur,int pre,ll par) {
	TP[cur]+=par;
	if(A[cur]) TP[cur]+=mo-C[cur]*A[cur]%mo;
	(V[cur]+=TP[cur]+N*A[cur])%=mo;
	FORR(e,E[cur]) if(e!=pre) {
		ll p=TP[cur]-TP[e]+mo;
		if(A[cur]) p=(p+A[cur]*(N-C[e]))%mo;
		prop2(e,cur,p);
	}
	TP[cur]=A[cur]=0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,-1);
	while(Q--) {
		cin>>i>>x;
		x--;
		if(i==1) {
			cin>>r;
			r=r*modpow(N)%mo;
			add.insert(x);
			(A[x]+=r)%=mo;
			
			if(add.size()>1200) {
				prop(0,-1);
				prop2(0,-1,0);
				add.clear();
			}
			
		}
		else {
			ll ret=V[x];
			FORR(a,add) {
				if(a==x) {
					(ret+=N*A[a])%=mo;
				}
				else if(L[a]<L[x] && L[x]<R[a]) {
					auto v=lower_bound(ALL(CL[a]),make_pair(L[x],0));
					(ret+=(N-C[v->second])*A[a])%=mo;
				}
				else {
					(ret+=C[a]*A[a])%=mo;
					
				}
			}
			cout<<ret<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}