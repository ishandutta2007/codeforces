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


int N,K,M;
set<pair<int,int>> S;
int num[404040];

int NV=1<<20;
int len[1<<21],ma[1<<21];

void update(int entry, int v) {
	entry += NV;
	len[entry]=v;
	ma[entry]=(entry-NV)+v-1;
	
	while(entry>1) {
		entry>>=1;
		if(len[entry*2]==0) {
			ma[entry]=ma[entry*2+1];
		}
		else if(len[entry*2+1]==0) {
			ma[entry]=ma[entry*2];
		}
		else {
			ma[entry]=max(ma[entry*2+1],ma[entry*2]+len[entry*2+1]);
		}
		len[entry]=len[entry*2]+len[entry*2+1];
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>M;
	while(M--) {
		cin>>x>>y;
		int t=y+abs(K-x);
		if(S.count({x,y})) {
			S.erase({x,y});
			num[t]--;
		}
		else {
			S.insert({x,y});
			num[t]++;
		}
		update(t,num[t]);
		
		if(len[1]==0) {
			cout<<0<<endl;
		}
		else {
			x=ma[1];
			cout<<max(0,x-N)<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}