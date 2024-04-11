#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int T;
int N;
vector<int> E[101010];

const ll mo=998244353;
ll pat[101010];
int C[101010];


int dfs(int cur,int pre,int v) {
	
	FORR(e,E[cur]) if(e!=pre) {
		if(dfs(e,cur,v)==0) return 0;
	}
	
	if(C[cur]%v==0) {
		C[pre]++;
	}
	else if((C[cur]+1)%v) {
		return 0;
	}
	else {
		if(cur==0) return 0;
	}
	return 1;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			E[i].clear();
			pat[i+1]=0;
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		for(i=N;i>=1;i--) {
			if((N-1)%i) continue;
			
			if(i==1) {
				pat[i]=1;
				FOR(j,N-1) pat[i]=pat[i]*2%mo;
			}
			else {
				FOR(j,N) C[j]=0;
				pat[i]=dfs(0,0,i);
			}
			
			for(j=i*2;j<=N;j+=i) (pat[i]+=mo-pat[j])%=mo;;
		}
		
		for(i=1;i<=N;i++) cout<<pat[i]<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}