#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string A,B;
string R;

string hoge(string a,string b,int first) {
	
	if(a.empty()) return "";
	int i,ma=-1;
	FOR(i,a.size()) {
		if(a[i]==b[0] && (i==0 || a[i]!=a[i-1])) {
			string r=a.substr(0,i)+a.substr(i+1);
			string t=hoge(r,b.substr(1),0);
			if(t!="z") return a[i]+t;
		}
		if(a[i]<b[0]) {
			string r=a.substr(0,i)+a.substr(i+1);
			return a[i]+r;
		}
	}
	
	return "z";
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	sort(ALL(A));
	reverse(ALL(A));
	
	if(A.size()!=B.size()) {
		cout<<A<<endl;
	}
	else {
		string C=hoge(A,B,1);
		while(C.size()>=2 && C[0]=='0') C=C.substr(1);
		cout<<C<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}