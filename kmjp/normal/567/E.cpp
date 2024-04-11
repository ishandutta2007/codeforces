#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,S[2];
int A[101010],B[101010];
ll L[101010];
vector<int> E[2][101010];
ll dist[2][101010];
ll pat[2][101010];
ll mo=1000000021LL;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S[0]>>S[1];
	S[0]--,S[1]--;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>L[i];
		A[i]--,B[i]--;
		E[0][A[i]].push_back(i);
		E[1][B[i]].push_back(i);
	}
	
	FOR(i,2) {
		FOR(x,N) dist[i][x]=1LL<<60;
		priority_queue<pair<ll,int> > Q;
		dist[i][S[i]]=0;
		pat[i][S[i]]=1;
		Q.push({-dist[i][S[i]],S[i]});
		
		while(Q.size()) {
			auto r=Q.top();
			Q.pop();
			ll co=-r.first;
			int cur=r.second;
			if(dist[i][cur]!=co) continue;
			
			FORR(r,E[i][cur]) {
				int tar=(i==0)?B[r]:A[r];
				if(dist[i][tar]>co+L[r]) {
					pat[i][tar]=pat[i][cur];
					dist[i][tar]=co+L[r];
					Q.push({-dist[i][tar],tar});
				}
				else if(dist[i][tar]==co+L[r]) {
					(pat[i][tar]+=pat[i][cur])%=mo;
				}
			}
		}
	}
	FOR(i,M) {
		ll best=dist[0][S[1]];
		ll my=dist[0][A[i]]+dist[1][B[i]]+L[i];
		
		if(best==my) {
			if(pat[0][A[i]]*pat[1][B[i]]%mo==pat[0][S[1]]) cout<<"YES"<<endl;
			else if(L[i]>1) cout<<"CAN 1"<<endl;
			else cout<<"NO"<<endl;
		}
		else if(dist[0][A[i]]+dist[1][B[i]]<best-1) cout<<"CAN "<<my-best+1<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}