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

string sub(string a,string b) { //a-b
	reverse(ALL(a));
	reverse(ALL(b));
	while(a.size()&&a.back()=='0') a.pop_back();
	while(b.size()&&b.back()=='0') b.pop_back();
	assert(a.size()>=b.size());
	string c;
	int i;
	int ca=0;
	FOR(i,a.size()) {
		int x=a[i]-'0';
		int y=(i<b.size())?(b[i]-'0'):0;
		if(x-(y+ca)<0) {
			c+='0'+(10+x-(y+ca));
			ca=1;
		}
		else {
			c+='0'+(x-(y+ca));
			ca=0;
		}
	}
	while(c.size()&&c.back()=='0') c.pop_back();
	if(c.empty()) c="0";
	reverse(ALL(c));
	return c;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		string R;
		if(S[0]=='9') {
			R=string(N+1,'1');
		}
		else {
			R=string(N,'9');
		}
		string ret=sub(R,S);
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}