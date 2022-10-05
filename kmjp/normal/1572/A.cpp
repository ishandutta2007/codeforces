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

int T,N;
vector<int> A[505050];
int in[505050];
int did[505050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			A[i].clear();
		}
		FOR(i,N) {
			in[i]=did[i]=0;
			cin>>k;
			FOR(j,k) {
				cin>>x;
				A[x-1].push_back(i);
				in[i]++;
			}
		}
		int ret=0;
		set<int> cand;
		FOR(i,N) if(in[i]==0) cand.insert(i);
		while(cand.size()) {
			ret++;
			int cur=-1;
			
			while(1) {
				auto it=cand.lower_bound(cur+1);
				if(it==cand.end()) break;
				cur=*it;
				cand.erase(cur);
				did[cur]=1;
				FORR(e,A[cur]) {
					if(--in[e]==0) cand.insert(e);
				}
			}
		}
		
		if(count(did,did+N,0)) ret=-1;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}