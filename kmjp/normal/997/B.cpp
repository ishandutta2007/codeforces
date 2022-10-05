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

ll N;
int mp[4*9*49+10];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,4*9*49) mp[i]=101010;
	mp[0]=0;
	queue<int> Q;
	Q.push(0);
	ll ret=0;
	while(Q.size()) {
		x=Q.front();
		if(mp[x]<=N) ret++;
		Q.pop();
		vector<int> V={4,9,49};
		FORR(v,V) {
			y=x+v;
			if(y>=4*9*49) continue;
			if(mp[y]<=mp[x]+1) continue;
			mp[y]=mp[x]+1;
			Q.push(y);
		}
	}
	
	FOR(i,49) {
		ll left=N-mp[((4*9)-1)*49+i];
		if(left>0) ret+=left;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}