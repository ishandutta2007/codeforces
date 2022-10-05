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
int N,M,K;
unordered_set<int> E[202020];
int NG[101010];
vector<pair<int,int>> EE;

int ok(unordered_set<int>& S) {
	FORR(s,S) {
		FORR(t,S) if(t<s&&E[s].count(t)==0) return 0;
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K;
		EE.clear();
		FOR(i,N) E[i].clear(), NG[i]=0;
		FOR(i,M) {
			cin>>x>>y;
			EE.push_back({x-1,y-1});
			E[x-1].insert(y-1);
			E[y-1].insert(x-1);
		}
		if(1LL*K*(K-1)/2>M) {
			cout<<-1<<endl;
			continue;
		}
		queue<int> Q;
		FOR(i,N) if(E[i].size()<K) NG[i]=1, Q.push(i);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(e,E[x]) {
				E[e].erase(x);
				if(NG[e]==0&&E[e].size()<K) {
					NG[e]=1;
					Q.push(e);
				}
			}
		}
		x=count(NG,NG+N,0);
		if(x) {
			cout<<1<<" "<<x<<endl;
			FOR(i,N) if(NG[i]==0) cout<<(i+1)<<" ";
			cout<<endl;
			continue;
		}
		FOR(i,N) E[i].clear(), NG[i]=0;
		FORR(e,EE) {
			E[e.first].insert(e.second);
			E[e.second].insert(e.first);
		}
		set<pair<int,int>> SS;
		FOR(i,N) SS.insert({E[i].size(),i});
		int ans=0;
		while(SS.size()) {
			x=SS.begin()->second;
			SS.erase(SS.begin());
			if(E[x].size()==K-1) {
				E[x].insert(x);
				if(ok(E[x])) {
					ans=1;
					cout<<2<<endl;
					FORR(e,E[x]) cout<<(e+1)<<" ";
					cout<<endl;
					break;
				}
				E[x].erase(x);
			}
			FORR(e,E[x]) {
				SS.erase({E[e].size(),e});
				E[e].erase(x);
				SS.insert({E[e].size(),e});
			}
			E[x].clear();
		}
		
		if(ans==0) cout<<-1<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}