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
int N,T;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T>>S;
	x=-1;
	int per=-1;
	for(i=0;i<S.size();i++) {
		
		if(per!=-1 && S[i]>='5') {
			x=i-1;
			for(j=i;j<S.size();j++) if(S[j]!='.') S[j]='0';
			T--;
			break;
		}
		if(S[i]=='.') per=i;
	}
	
	if(i==S.size()) {
		cout<<S<<endl;
		return;
	}
	
	int carry=1;
	for(i=x;i>=0;i--) {
		if(S[i]=='.') continue;
		if(carry==1) {
			carry=0;
			if(S[i]=='9') {
				S[i]='0';
				carry=1;
			}
			else {
				S[i]++;
				if(i>per && S[i]>='5' && T) {
					S[i]='0';
					T--;
					carry=1;
				}
			}
		}
		else {
			if(i>per && S[i]>='5' && T) {
				S[i]='0';
				T--;
				carry=1;
			}
		}
	}
	if(carry) S="1"+S;
	
	if(count(S.begin(),S.end(),'.')) {
		while(S.back()=='0') S.pop_back();
	}
	if(S.back()=='.') S.pop_back();
	cout<<S<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}