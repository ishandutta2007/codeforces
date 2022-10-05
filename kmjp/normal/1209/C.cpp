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

int T;
int N;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		string R;
		for(i=0;i<9;i++) {
			string A,B;
			int la=-1;
			R.clear();
			FOR(j,N) if(S[j]-'0'<i) la=j;
			FOR(j,N) {
				if(S[j]-'0'<i || (j>=la && S[j]-'0'==i)) {
					if(A.size() && A.back()>S[j]) break;
					A.push_back(S[j]);
					R+='1';
				}
				else {
					if(B.size() && B.back()>S[j]) break;
					B.push_back(S[j]);
					R+='2';
				}
			}
			if(A.size()+B.size()==N) {
				cout<<R<<endl;
				break;
			}
		}
		if(i==9) cout<<"-"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}