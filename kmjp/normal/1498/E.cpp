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
int K[505];
int R[505][505];

int ask(int x,int y) {
	cout<<"? "<<(x+1)<<" "<<(y+1)<<endl;
	string s;
	cin>>s;
	return s=="Yes";
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>K[i];
	vector<pair<int,int>> V;
	FOR(y,N) FOR(x,y) V.push_back({abs(K[y]-K[x]),y*1000+x});
	sort(ALL(V));
	reverse(ALL(V));
	
	FORR(v,V) {
		y=v.second/1000;
		x=v.second%1000;
		if(K[x]<K[y]) swap(x,y);
		
		if(ask(x,y)) {
			cout<<"! "<<(x+1)<<" "<<(y+1)<<endl;
			return;
		}
	}
	cout<<"! 0 0"<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}