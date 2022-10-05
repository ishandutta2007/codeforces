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

int N,M,K;
int L[101010],R[101010];
int ID[101010];
vector<pair<int,int>> add;

int from[256];
int to[256];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	
	FOR(i,N) {
		cin>>L[i]>>R[i];
		L[i]--;
		add.push_back({L[i],i+N});
		add.push_back({R[i],i});
	}
	int mask=0;
	sort(ALL(add));
	
	FOR(i,256) from[i]=-1<<30;
	from[0]=0;
	int pre=0;
	
	FORR(v,add) {
		FOR(i,256) if(__builtin_popcount(i)%2==1) from[i]+=v.first-pre;
		pre=v.first;
		if(v.second<N) {
			x=ID[v.second];
			mask ^= 1<<x;
			FOR(i,256) if(i&(1<<x)) {
				from[i^(1<<x)]=max(from[i^(1<<x)],from[i]);
				from[i]=-1<<30;
			}
		}
		else {
			FOR(i,8) if((mask&(1<<i))==0)  break;
			
			x=ID[v.second-N]=i;
			mask ^= 1<<x;
			FOR(i,256) if(i&(1<<x)) from[i]=from[i^(1<<x)];
		}
	}
	
	int ret=0;
	FOR(i,256) ret=max(ret,from[i]+(__builtin_popcount(i)%2)*(M-pre));
	cout<<ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}