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
int P[202020];
vector<int> E[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>P[i+1];
			P[i+1]--;
			E[P[i+1]].push_back(i+1);
		}
		vector<int> R;
		R.push_back(1);
		FOR(i,N) if(E[i].size()) R.push_back(E[i].size());
		sort(ALL(R));
		reverse(ALL(R));
		int mi=1<<30;
		for(i=29;i>=0;i--) {
			int tmp=mi-(1<<i);
			if(tmp<R.size()) continue;
			int aff=0;
			FOR(j,R.size()) {
				int fin=j+R[j];
				if(fin>tmp) aff+=fin-tmp;
			}
			if(aff<=tmp-(int)R.size()) mi=tmp;
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