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
int A[101][101];

void ans(int y,int x,int v) {
	A[y][x]=v;
	cout<<v<<" "<<(y+1)<<" "<<(x+1)<<endl;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<int,int>> C[2];
	FOR(y,N) FOR(x,N) C[(y+x)%2].push_back({y,x});
	FOR(i,N*N) {
		cin>>x;
		if(x==1) {
			if(C[1].size()) {
				ans(C[1].back().first,C[1].back().second,2);
				C[1].pop_back();
			}
			else {
				ans(C[0].back().first,C[0].back().second,3);
				C[0].pop_back();
			}
		}
		else if(x==2) {
			if(C[0].size()) {
				ans(C[0].back().first,C[0].back().second,1);
				C[0].pop_back();
			}
			else {
				ans(C[1].back().first,C[1].back().second,3);
				C[1].pop_back();
			}
		}
		else if(x==3) {
			if(C[0].size()) {
				ans(C[0].back().first,C[0].back().second,1);
				C[0].pop_back();
			}
			else {
				ans(C[1].back().first,C[1].back().second,2);
				C[1].pop_back();
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}