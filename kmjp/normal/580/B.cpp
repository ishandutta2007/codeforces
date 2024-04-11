#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,D;
int M[101010],S[101010];
pair<int,int> P[101010];
ll sum[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	FOR(i,N) cin>>P[i].first>>P[i].second;
	sort(P,P+N);
	FOR(i,N) sum[i+1]=sum[i]+P[i].second;
	
	ll ma=0;
	x=0;
	FOR(y,N) {
		while(P[x].first+D<=P[y].first) x++;
		ma=max(ma,sum[y+1]-sum[x]);
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}