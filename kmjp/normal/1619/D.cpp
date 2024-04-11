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
int H,W;
vector<int> P[101010];
int A[101010];
int ok[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		ll sum=0;
		FOR(y,H) {
			P[y].resize(W);
			FOR(x,W) {
				cin>>P[y][x];
			}
		}
		int ret=0;
		for(i=29;i>=0;i--) {
			int tmp=ret+(1<<i);
			FOR(j,W) ok[j]=0;
			int num=0;
			FOR(y,H) {
				k=0;
				FOR(x,W) if(P[y][x]>=tmp) ok[x]=1, k++;
				if(k>=2) num=1;
			}
			if(num&&count(ok,ok+W,1)==W) {
				ret=tmp;
			}
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