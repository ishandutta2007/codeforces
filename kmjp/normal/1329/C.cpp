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
int G,H;
int A[1<<21];
int hei[2<<20];

vector<int> R;

int trydfs(int cur) {
	if(A[2*cur]==0 && A[2*cur+1]==0) {
		return cur;
	}
	if(A[2*cur]>A[2*cur+1]) return trydfs(2*cur);
	return trydfs(2*cur+1);
}

int godfs(int cur) {
	int ret=A[cur];
	if(A[2*cur]==0 && A[2*cur+1]==0) {
		A[cur]=0;
	}
	else {
		if(A[2*cur]>A[2*cur+1]) {
			A[cur]=godfs(2*cur);
		}
		else {
			A[cur]=godfs(2*cur+1);
		}
	}
	return ret;
}



void dfs(int cur) {
	while(A[cur]) {
		int tr=trydfs(cur);
		if(hei[tr]<=G) break;
		R.push_back(cur);
		godfs(cur);
	}
	if(A[cur]==0) return;
	dfs(cur*2);
	dfs(cur*2+1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	FOR(i,20) {
		FOR(j,1<<i) hei[(1<<i)+j]=i+1;
	}
	
	cin>>T;
	while(T--) {
		cin>>H>>G;
		R.clear();
		FOR(i,(1<<H)-1) {
			cin>>A[i+1];
		}
		dfs(1);
		
		ll sum=0;
		for(i=1;i<(1<<G);i++) sum+=A[i];
		cout<<sum<<endl;
		FORR(v,R) cout<<v<<" ";
		cout<<endl;
		FOR(i,(1<<H)-1) A[i+1]=0;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}