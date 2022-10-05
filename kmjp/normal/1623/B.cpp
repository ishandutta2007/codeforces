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
int T,N,L[1010],R[1010];
int num[1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ZERO(num);
		FOR(i,N) {
			cin>>L[i]>>R[i];
			for(x=L[i];x<=R[i];x++) num[x]++;
		}
		queue<pair<int,int>> Q;
		Q.push({1,N});
		while(Q.size()) {
			auto a=Q.front();
			Q.pop();
			y=-1;
			for(x=a.first;x<=a.second;x++) {
				num[x]--;
				if(num[x]==0) y=x;
			}
			cout<<a.first<<" "<<a.second<<" "<<y<<endl;
			if(y>a.first) Q.push({a.first,y-1});
			if(y<a.second) Q.push({y+1,a.second});
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}