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
int N,K;
int D[202020];
int C[202020];
int F[202020];
vector<int> E[202020];
int L[202020],R[202020],id;
int ma[202020];

void dfs(int cur,int pre,int d) {
	D[cur]=d;
	F[cur]=-1;
	L[cur]=id;
	if(C[cur]) F[cur]=d/2;
	if(cur&&E[cur].size()==1) id++;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur,d+1);
		if(F[e]>=1) F[cur]=max(F[cur],F[e]-1);
	}
	R[cur]=id;
	if(F[cur]==0) {
		ma[L[cur]]=max(ma[L[cur]],R[cur]);
	}
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			D[i]=1<<30;
			C[i]=0;
			E[i].clear();
			F[i]=-1;
			ma[i]=-1;
		}
		FOR(i,K) {
			cin>>x;
			C[x-1]++;
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}

		id=0;
		dfs(0,0,0);
		
		int num=0;
		int ra=0;
		i=0;
		int pre=0;
		int tar=0;
		while(tar<id) {
			int a=-1;
			for(i=pre;i<=tar;i++) {
				a=max(a,ma[i]);
			}
			if(a<=tar) {
				num=-1;
				break;
			}
			num++;
			pre=tar+1;
			tar=a;
		}
		cout<<num<<endl;
		
	}
		
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}