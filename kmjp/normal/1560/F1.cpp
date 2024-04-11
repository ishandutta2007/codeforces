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
string S;
int K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S>>K;
		
		map<char,int> M;
		FORR(c,S) M[c]++;
		if(M.size()<=K) {
			cout<<S<<endl;
			continue;
		}
		
		for(int len=S.size();len>=1;len--) {
			for(x=S[len-1]-'0'+1;x<=9;x++) {
				string T=S.substr(0,len-1)+(char)(x+'0');
				
				map<char,int> M;
				FORR(c,T) M[c]++;
				
				if(M.size()<K) {
					T+=string(S.size()-T.size(),'0');
					cout<<T<<endl;
					break;
				}
				if(M.size()==K) {
					char c=M.begin()->first;
					T+=string(S.size()-T.size(),c);
					cout<<T<<endl;
					break;
					
				}
				
				
				
			}
			if(x<10) break;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}