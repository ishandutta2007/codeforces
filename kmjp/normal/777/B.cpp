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
string A,B;
int cnt[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	FORR(c,A) c-='0';
	FORR(c,B) c-='0', cnt[c]++;
	
	sort(ALL(A));
	int ret=0;
	FORR(c,A) {
		for(i=c;i<=9;i++) {
			if(cnt[i]) {
				cnt[i]--;
				break;
			}
		}
		if(i==10) ret++;
	}
	cout<<ret<<endl;
	
	ret=0;
	ZERO(cnt);
	FORR(c,B) cnt[c]++;
	FORR(c,A) {
		for(i=c+1;i<=9;i++) {
			if(cnt[i]) {
				ret++;
				cnt[i]--;
				break;
			}
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}