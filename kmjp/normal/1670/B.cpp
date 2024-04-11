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

int T,N,K;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		int C[26]={};
		cin>>K;
		FOR(i,K) {
			cin>>s;
			C[s[0]-'a']++;
		}
		vector<int> V;
		x=0;
		FORR(c,S) {
			if(C[c-'a']) {
				V.push_back(x);
				x=0;
			}
			else {
				x++;
			}
		}
		int ret=0;
		while(V.size()>1) {
			vector<int> W;
			ret++;
			FORR(a,V) {
				if(a) {
					W.push_back(a-1);
				}
				else if(W.size()) {
					continue;
				}
				else {
					W.push_back(0);
				}
			}
			V=W;
		}
		if(V.size()==1) ret+=V[0];
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}