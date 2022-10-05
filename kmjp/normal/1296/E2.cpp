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
ll mask[26];
int R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	int ma=0;
	FOR(i,N) {
		ll m=0;
		for(j=S[i]-'a'+1;j<26;j++) m|=mask[j];
		FOR(j,64) {
			if((m&(1LL<<j))==0) {
				R[i]=j+1;
				ma=max(ma,R[i]);
				mask[S[i]-'a'] |= 1LL<<j;
				break;
			}
		}
	}
	
	cout<<ma<<endl;
	FOR(i,N) cout<<R[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}