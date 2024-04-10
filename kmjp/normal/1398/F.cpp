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
int nex[1010101][3];
int num[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	set<int> alive;
	cin>>N>>S;
	nex[N][0]=nex[N][1]=nex[N][2]=N;
	
	for(i=N-1;i>=0;i--) {
		nex[i][0]=nex[i+1][0];
		nex[i][1]=nex[i+1][1];
		nex[i][2]=nex[i+1][2];
		if(S[i]=='0') nex[i][0]=i;
		if(S[i]=='1') nex[i][1]=i;
		if(S[i]=='?') nex[i][2]=i;
	}
	for(i=0;i<=N;i++) alive.insert(i);
	for(i=1;i<=N;i++) {
		int cur=0;
		while(cur<N) {
			cur=*alive.lower_bound(cur);
			
			
			x=max(nex[cur][0],nex[cur][1]);
			//cout<<"!"<<cur<<" "<<num[i]<<" "<<x<<endl;
			if(x-cur>=i) {
				num[i]+=(x-cur)/i;
				cur+=(x-cur)/i*i;
			}
			else {
				
				if(S[cur]=='?') {
					alive.erase(cur);
					cur++;
				}
				else {
					auto it=alive.lower_bound(cur);
					while(1) {
						if(it!=alive.end() && *it<x && *it<nex[cur][2]) {
							it=alive.erase(it);
						}
						else break;
					}
				}
			}
		}
		cout<<num[i]<<" ";
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}