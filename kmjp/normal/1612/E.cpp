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

int N;
vector<int> C[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		C[x].push_back(y);
	}
	double ma=0;
	vector<int> ret;
	for(k=1;k<=20;k++) {
		vector<pair<double,int>> V;
		for(i=1;i<=200000;i++) {
			double a=0;
			FORR(c,C[i]) {
				a+=1.0*min(c,k)/k;
			}
			V.push_back({a,i});
		}
		sort(ALL(V));
		reverse(ALL(V));
		double s=0;
		FOR(i,k) s+=V[i].first;
		if(s>ma) {
			ma=s;
			ret.clear();
			FOR(i,k) ret.push_back(V[i].second);
			sort(ALL(ret));
		}
		
	}
	
	cout<<ret.size()<<endl;
	FORR(r,ret) cout<<r<<" ";
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}