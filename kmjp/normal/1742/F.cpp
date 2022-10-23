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

int T,Q;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		ll C[2][27]={};
		C[0][0]=C[1][0]=1;
		cin>>Q;
		while(Q--) {
			cin>>i>>j>>s;
			FORR(c,s) C[i-1][c-'a']+=j;
			
			ll D[2][26];
			FOR(i,2) FOR(j,26) D[i][j]=C[i][j];
			i=0,j=25;
			while(1) {
				if(j<0) {
					cout<<"NO"<<endl;
					break;
				}
				else if(i>25) {
					cout<<"YES"<<endl;
					break;
				}
				if(D[1][j]==0) {
					j--;
					continue;
				}
				if(D[0][i]==0) {
					i++;
					continue;
				}
				if(i>j) {
					cout<<"NO"<<endl;
					break;
				}
				if(i<j) {
					cout<<"YES"<<endl;
					break;
				}
				ll a=min(D[0][i],D[1][j]);
				D[0][i]-=a;
				D[1][j]-=a;
				
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