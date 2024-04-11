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

int N,M;
map<int,int> V[101010];
int ma=0;
void add(int U,int W,int num) {
	auto it=V[U].lower_bound(W+1);
	it--;
	
	if(it->second>=num) return;
	V[U][W]=num;
	while(1) {
		auto it=V[U].lower_bound(W+1);
		if(it==V[U].end()) break;
		if(it->second>num) break;
		V[U].erase(it);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y,w; string s;
	
	cin>>N>>M;
	FOR(i,N) V[i][-1]=0;
	FOR(i,M) {
		cin>>x>>y>>w;
		x--,y--;
		auto it=V[x].lower_bound(w);
		it--;
		ma=max(ma,it->second+1);
		add(y,w,it->second+1);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}