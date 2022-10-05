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
ll N,M;
int num[62];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		ZERO(num);
		ll sum=0;
		FOR(i,M) {
			cin>>x;
			y=0;
			while(1<<(y+1)<=x) y++;
			num[y]++;
		}
		ll ret=0;
		FOR(i,60) {
			if(N&(1LL<<i)) {
				if(num[i]) {
					num[i]--;
				}
				else {
					for(j=i+1;j<60;j++) if(num[j]) break;
					if(j==60) {
						ret=-1;
						break;
					}
					ret+=j-i;
					num[j]--;
					for(x=i+1;x<j;x++) num[x]++;
				}
			}
			num[i+1]+=num[i]/2;
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}