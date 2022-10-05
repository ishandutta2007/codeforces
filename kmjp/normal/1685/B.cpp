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


int T,A,B,C,D;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C>>D>>S;
		int NA=0;
		int NB=0;
		vector<string> V;
		string cur;
		FORR(c,S) {
			if(c=='A') NA++;
			if(c=='B') NB++;
			if(cur.size()&&cur.back()==c) {
				V.push_back(cur);
				cur="";
			}
			cur+=c;
		}
		V.push_back(cur);
		if(NA!=A+C+D||NB!=B+C+D) {
			cout<<"NO"<<endl;
			continue;
		}
		vector<int> X[3];
		FORR(c,V) {
			if(c.size()%2) X[0].push_back(c.size()/2);
			else X[c[0]-'A'+1].push_back(c.size()/2);
		}
		sort(ALL(X[1]));
		FORR(a,X[1]) {
			x=min(a,C);
			a-=x;
			C-=x;
			x=max(0,min(a-1,D));
			D-=x;
		}
		sort(ALL(X[2]));
		FORR(a,X[2]) {
			x=min(a,D);
			a-=x;
			D-=x;
			x=max(0,min(a-1,C));
			C-=x;
		}
		C+=D;
		FORR(v,X[0]) C-=v;
		if(C<=0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}