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
string S;
int P[2020];
int vis[2020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		FOR(i,N) {
			cin>>P[i];
			P[i]--;
			vis[i]=0;
		}
		ll ret=1;
		FOR(i,N) if(vis[i]==0) {
			string V;
			x=i;
			while(vis[x]==0) {
				vis[x]=1;
				V+=S[x];
				x=P[x];
			}
			for(j=1;j<=V.size();j++) if(V.size()%j==0) {
				for(x=0;x<V.size();x+=j) if(V.substr(0,j)!=V.substr(x,j)) break;
				if(x!=V.size()) continue;
				ret=ret/__gcd(ret,(ll)j)*j;
				break;
				
				
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