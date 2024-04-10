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
int N;
map<string,string> P;
map<string,string> S;
map<string,ll> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		P.clear();
		S.clear();
		M.clear();
		string V,op;
		while(N--) {
			cin>>V>>op;
			if(op==":=") {
				cin>>s;
				if(s.size()<=3) {
					P[V]=S[V]=s;
					M[V]=0;
				}
				else {
					P[V]=s.substr(0,3);
					S[V]=s.substr(s.size()-3);
					x=0;
					for(i=0;i+4<=s.size();i++) if(s.substr(i,4)=="haha") x++;
					M[V]=x;
				}
			}
			else {
				string a,b;
				cin>>a>>op>>b;
				string pre=P[a]+P[b];
				string suf=S[a]+S[b];
				ll x=M[a]+M[b];
				if(pre.size()>3) pre=pre.substr(0,3);
				if(suf.size()>3) suf=suf.substr(suf.size()-3);
				s=S[a]+P[b];
				for(i=0;i+4<=s.size();i++) if(s.substr(i,4)=="haha") x++;
				P[V]=pre;
				S[V]=suf;
				M[V]=x;
			}
			
		}
		
		cout<<M[V]<<endl;;
	}

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}