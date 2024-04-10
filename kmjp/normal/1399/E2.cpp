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
int N;
ll S;
vector<vector<ll>> E[202020];
int C[202020];
int P[202020];

int dfs(int cur,int pre) {
	if(E[cur].size()==1 && cur) C[cur]=1;
	P[cur]=pre;
	FORR(e,E[cur]) if(e[0]!=pre) C[cur]+=dfs(e[0],cur);
	return C[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		FOR(i,N) E[i].clear(), C[i]=0;
		FOR(i,N-1) {
			k=1;
			cin>>x>>y>>r>>k;
			
			E[x-1].push_back({y-1,r,k});
			E[y-1].push_back({x-1,r,k});
			
		}
		dfs(0,-1);
		
		ll sum=0;
		vector<ll> V[3];
		FOR(i,N) if(i) {
			FORR(e,E[i]) if(e[0]==P[i]) {
				ll a=e[1];
				ll b=C[i];
				sum+=a*b;
				while(a) {
					V[e[2]].push_back((a-a/2)*b);
					a/=2;
				}
			}
		}
		sort(ALL(V[1]));
		reverse(ALL(V[1]));
		sort(ALL(V[2]));
		reverse(ALL(V[2]));
		vector<ll> VS[3];
		FOR(i,3) {
			VS[i].push_back(0);
			FORR(v,V[i]) VS[i].push_back(VS[i].back()+v);
		}
		
		
		int num=1<<30;
		for(i=0;i<=V[1].size();i++) {
			ll cur=sum-VS[1][i];
			if(cur<=S) {
				num=min(num,i);
			}
			else {
				ll lef=cur-S;
				if(VS[2].back()>=lef) {
					x=lower_bound(ALL(VS[2]),lef)-VS[2].begin();
					num=min(num,i+2*x);
				}
			}
		}
		cout<<num<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}