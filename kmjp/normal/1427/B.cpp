#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T,N,K;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>S;
		x=0;
		while(S.size()&&S.back()=='L') x++,S.pop_back();
		reverse(ALL(S));
		while(S.size()&&S.back()=='L') x++,S.pop_back();
		
		if(S.empty()) {
			K=min(K,x);
			cout<<max(0,2*K-1)<<endl;
			continue;
		}
		
		y=0;
		vector<int> C;
		int p=0;
		int tot=0;
		FORR(c,S) {
			if(c=='L') y++;
			else {
				if(y) {
					C.push_back(y);
					y=0;
				}
				if(p=='W') tot+=2;
				else tot++;
			}
			
			p=c;
		}
		sort(ALL(C));
		reverse(ALL(C));
		while(C.size()&&K) {
			if(C.back()==1) {
				tot+=3;
				C.pop_back();
			}
			else {
				tot+=2;
				C.back()--;
			}
			K--;
		}
		tot+=2*min(x,K);
		cout<<tot<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}