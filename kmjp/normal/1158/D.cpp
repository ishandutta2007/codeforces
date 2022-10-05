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
ll X[2020],Y[2020];
string S;
int vis[2020];

ll lef(int a,int b,int c) {
	return (X[b]-X[a])*(Y[c]-Y[a])>(Y[b]-Y[a])*(X[c]-X[a]);
}

void solve() {
	int i,j,k,l,r,x,y;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	cin>>S;
	
	int s=0;
	FOR(i,N) if(X[i]<X[s]) s=i;
	vector<int> V;
	V.push_back(s);
	vis[s]=1;
	FORR(c,S) {
		int cur=V.back();
		int cand=-1;
		FOR(i,N) if(vis[i]==0) {
			if(cand==-1) {
				cand=i;
			}
			else {
				if(lef(cur,cand,i)==(c=='R')) cand=i;
			}
		}
		vis[cand]=1;
		V.push_back(cand);
	}
	FOR(i,N) if(vis[i]==0) V.push_back(i);
	FORR(v,V) cout<<(v+1)<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}