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

int H,W,K;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	
	FOR(y,H-1) {
		S+=string(W-1,'R');
		S+=string(W-1,'L');
		S+=string(1,'D');
	}
	FOR(x,W-1) {
		S+=string(1,'R');
		S+=string(H-1,'U');
		S+=string(H-1,'D');
	}
	S+=string(W-1,'L');
	S+=string(H-1,'U');
	if(K>S.size()) {
		return _P("NO\n");
	}
	vector<pair<int,char>> V;
	FOR(i,K) {
		if(V.empty() || V.back().second!=S[i]) V.push_back({0,S[i]});
		V.back().first++;
	}
	cout<<"YES"<<endl;
	cout<<V.size()<<endl;
	FORR(v,V) {
		cout<<v.first<<" "<<v.second<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}