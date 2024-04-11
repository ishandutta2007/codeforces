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

int N;
string S[2],T;

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S[0]>>S[1];
	N--;
	FOR(i,N) {
		if(S[1][i]=='N') S[1][i]='S';
		else if(S[1][i]=='S') S[1][i]='N';
		else if(S[1][i]=='E') S[1][i]='W';
		else if(S[1][i]=='W') S[1][i]='E';
	}
	reverse(ALL(S[0]));
	T=S[0]+"#"+S[1];
	auto v=Zalgo(T);
	
	for(i=1;i<=N;i++) if(v[v.size()-i]==i) return _P("NO\n");
	
	
	
	return _P("YES\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}