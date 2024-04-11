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
int N,A[10101];
int from[2020];
int to[2020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,2020) from[i]=1<<20;
		from[0]=0;
		FOR(i,N) {
			cin>>x;
			FOR(j,2020) to[j]=1<<20;
			FOR(j,2020) if(from[j]<1<<20) {
				// add
				if(j+x<=2000) {
					if(from[j]<=x) to[j+x]=0;
					else to[j+x]=min(to[j+x],from[j]-x);
				}
				//del
				if(x<=j) to[j-x]=min(to[j-x],from[j]+x);
				else if(x+from[j]<=2000) to[x+from[j]]=0;
			}
			swap(from,to);
		}
		int ret=1<<20;
		FOR(i,2020) ret=min(ret,i+from[i]);
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}