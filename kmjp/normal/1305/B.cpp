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
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	int L=0,R=N-1;
	vector<int> V;
	while(L<R) {
		while(L<R && S[L]==')') L++;
		while(L<R && S[R]=='(') R--;
		if(S[L]=='(' && S[R]==')') {
			V.push_back(L);
			V.push_back(R);
			L++;
			R--;
		}
		else {
			break;
		}
	}
	if(V.empty()) {
		cout<<0<<endl;
	}
	else {
		cout<<1<<endl;
		cout<<V.size()<<endl;
		sort(ALL(V));
		FORR(v,V) cout<<(v+1)<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}