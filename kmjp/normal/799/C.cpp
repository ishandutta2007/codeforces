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

int N,C,D;
vector<pair<int,int>> E[2];

int hoge(int P,vector<pair<int,int>> V) {
	int ma=-1<<30;
	
	if(V.size()<2) return 0;
	sort(ALL(V));
	vector<int> M;
	M.push_back(V[0].second);
	for(int i=1;i<V.size();i++) M.push_back(max(M[i-1],V[i].second));
	
	int x=-1,y;
	for(y=V.size()-1;y>=1;y--) {
		while(x+1<V.size() && V[x+1].first+V[y].first<=P) x++;
		if(x>=0) ma=max(ma,V[y].second+M[min(x,y-1)]);
	}
	return ma;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C>>D;
	FOR(i,N) {
		cin>>x>>y>>s;
		E[s=="D"].push_back({y,x});
	}
	
	int a=-1<<30,b=-1<<30;
	FORR(r,E[0]) if(r.first<=C) a=max(a,r.second);
	FORR(r,E[1]) if(r.first<=D) b=max(b,r.second);
	cout<<max({0,a+b,hoge(C,E[0]),hoge(D,E[1])})<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}