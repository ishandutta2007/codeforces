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

ll N,M;

ll did[1010101];

vector<int> V[22];
int C[22];


vector<int> W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	W.resize(M);
	vector<int> V;
	for(i=1;i<=19;i++) {
		vector<int> X;
		
		for(j=1;j<=M;j++) W[j-1]=i*j;
		x=y=0;
		while(x<V.size()||y<W.size()) {
			if(y==W.size()) {
				X.push_back(V[x++]);
			}
			else if(x==V.size()) {
				X.push_back(W[y++]);
			}
			else if(V[x]==W[y]) {
				X.push_back(W[y++]);
				x++;
			}
			else if(V[x]<W[y]) {
				X.push_back(V[x++]);
			}
			else {
				X.push_back(W[y++]);
			}
		}
		C[i]=X.size();
		swap(V,X);
	}
	
	
	ll ret=1;
	for(i=2;i<=N;i++) if(did[i]==0) {
		x=1;
		ll a=i;
		while(a*i<=N) a*=i,x++, did[a]=1;
		ret+=C[x];
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}