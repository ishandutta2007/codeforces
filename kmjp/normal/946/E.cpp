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

int T,N;
string S;

string decdec(string A) {
	for(int i=A.size()-1;i>=0;i--) {
		if(A[i]--!='0') break;
		A[i]='9';
	}
	A=A.substr(A[0]=='0');
	if(A.empty()) A="0";
	return A;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		S=decdec(S);
		N=S.size();
		
		if(N%2==1) {
			FOR(i,N-1) cout<<9;
			cout<<endl;
			continue;
		}
		if(S[0]=='1' && count(ALL(S),'0')==N-1) {
			FOR(i,N-2) cout<<9;
			cout<<endl;
			continue;
		}
		int mask=0;
		FORR(c,S) mask ^= 1<<(c-'0');
		if(mask==0) {
			cout<<S<<endl;
			continue;
		}
		FOR(i,N) {
			mask ^= 1<<(S[N-1-i]-'0');
			for(j=S[N-1-i]-'0'-1;j>=0;j--) {
				int mask2=mask^(1<<j);
				if(__builtin_popcount(mask2)<=i && (i-__builtin_popcount(mask2))%2==0) {
					S[N-1-i]=j+'0';
					for(j=i-1;j>=0;j--) {
						if(j+1>__builtin_popcount(mask2)) {
							S[N-1-j]='9';
						}
						else {
							for(x=9;x>=0;x--) if(mask2&(1<<x)) {
								S[N-1-j]=x+'0';
								mask2^=1<<x;
								break;
							}
						}
					}
					i=N;
					break;
				}
			}
		}
		cout<<S<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}