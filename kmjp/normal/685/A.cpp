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

ll N,M;
int ND,MD;
set<string> R;

int dig(int v) {
	int d=0;
	while(v) {
		d++;
		v/=7;
	}
	return d;
}

int hoge(string s) {
	int v=0;
	FORR(c,s) v=v*7+(c-'0');
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	ND=dig(N-1);
	MD=dig(M-1);
	if(ND==0) ND=1;
	if(MD==0) MD=1;
	if(ND+MD>7) return _P("0\n");
	
	string S;
	FOR(i,7) S += '0'+i;
	
	do {
		string a=S.substr(0,ND);
		string b=S.substr(ND,MD);
		if(hoge(a)<N && hoge(b)<M) R.insert(a+":"+b);
		
	} while(next_permutation(ALL(S)));
	
	cout<<R.size()<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}