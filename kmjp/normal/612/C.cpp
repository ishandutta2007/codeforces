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

string S;
vector<int> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int num=0;
	cin>>S;
	FORR(r,S) {
		if(r=='{') x=1;
		if(r=='}') x=-1;
		if(r=='<') x=2;
		if(r=='>') x=-2;
		if(r=='[') x=3;
		if(r==']') x=-3;
		if(r=='(') x=4;
		if(r==')') x=-4;
		
		if(x>0) V.push_back(x);
		else {
			if(V.empty()) return _P("Impossible\n");
			num += (V.back()!=-x);
			V.pop_back();
		}
	}
	if(!V.empty()) return _P("Impossible\n");
	cout<<num<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}