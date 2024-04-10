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

int N;
int X[101010],Y[101010],Z[101010];
vector<int> Xs;
vector<pair<int,int>> R;
vector<vector<int>> V[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>Z[i];
		Xs.push_back(X[i]);
	}
	sort(ALL(Xs));
	FOR(i,N) {
		X[i]=lower_bound(ALL(Xs),X[i])-Xs.begin();
		V[X[i]].push_back({Y[i],Z[i],i});
	}
	vector<int> L;
	FOR(i,Xs.size()) {
		sort(ALL(V[i]));
		vector<vector<int>> T;
		FORR(v,V[i]) {
			if(T.empty() || T.back()[0]!=v[0]) {
				T.push_back(v);
			}
			else {
				R.push_back({T.back()[2]+1,v[2]+1});
				T.pop_back();
			}
		}
		if(T.size()%2==1) {
			L.push_back(T.back()[2]);
			T.pop_back();
		}
		FOR(x,T.size()/2) R.push_back({T[x*2][2]+1,T[x*2+1][2]+1});
	}
	FOR(x,L.size()/2) R.push_back({L[x*2]+1,L[x*2+1]+1});
	
	FORR(r,R) cout<<r.first<<" "<<r.second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}