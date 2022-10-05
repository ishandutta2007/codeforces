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
int K;
string S;

const int prime_max = 1000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	divp[1]=1;
	cin>>T;
	while(T--) {
		cin>>K>>S;
		string A=S;
		
		FOR(x,K) {
			int v=S[x]-'0';
			if(divp[v]) A=S.substr(x,1);
			FOR(y,x) {
				int v=(S[y]-'0')*10+S[x]-'0';
				if(divp[v]&&A.size()>2) A=S.substr(y,1)+S.substr(x,1);
				FOR(k,y) {
					int v=(S[k]-'0')*10+(S[y]-'0')*10+S[x]-'0';
					if(divp[v]&&A.size()>3) A=S.substr(k,1)+S.substr(y,1)+S.substr(x,1);
				}
				
			}
		}
		cout<<A.size()<<endl;
		cout<<A<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}