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
int A[201010];
int R[201010];
int TR[201010];
set<int> S[201010];

vector<int> cand[201010];
int ev[201010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		vector<int> As;
		FOR(i,N) {
			cin>>A[i];
			As.push_back(A[i]);
			R[i]=i;
			TR[i]=-1;
			S[i].clear();
			cand[i].clear();
			ev[i]=-1;
		}
		sort(ALL(As));
		FOR(i,N) {
			A[i]=lower_bound(ALL(As),A[i])-As.begin();
			S[A[i]].insert(i);
		}
		FOR(i,M) {
			cin>>x>>y;
			R[x-1]=max(R[x-1],y-1);
		}
		multiset<int> need;
		multiset<int> fail;
		FOR(i,N) {
			if(i) R[i]=max(R[i],R[i-1]);
			auto it=S[A[i]].lower_bound(R[i]+1);
			it--;
			if(*it==i) continue;
			auto it2=S[A[i]].find(i);
			need.insert(*prev(it));
			ev[i]=*it;
			fail.insert(*next(it2));
			
		}
		
		int ret=N;
		FOR(i,N) {
			if(need.empty()) {
				ret=0;
			}
			else {
				ret=min(ret,*need.rbegin()+1-i);
				if(ev[i]>=0) need.insert(ev[i]);
			}
			if(fail.count(i)) break;
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