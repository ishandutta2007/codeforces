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

int H,W;
string S[101];

bool ispar(int a,int b) {
	int i;
	FOR(i,S[a].size()) if(S[a][i]!=S[b][S[a].size()-1-i]) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	string R;
	FOR(y,H) FOR(x,y) if(ispar(x,y)) {
		string C=S[x]+S[y];
		int vis[101]={};
		vis[x]=vis[y]=1;
		FOR(i,H) if(vis[i]==0) {
			vis[i]=1;
			FOR(j,H) if(vis[j]==0&&ispar(i,j)) {
				C=S[i]+C+S[j];
				vis[j]=1;
				break;
			}
		}
		if(C.size()>R.size()) R=C;
	}
	FOR(x,H) if(ispar(x,x)) {
		string C=S[x];
		int vis[101]={};
		vis[x]=1;
		FOR(i,H) if(vis[i]==0) {
			vis[i]=1;
			FOR(j,H) if(vis[j]==0&&ispar(i,j)) {
				C=S[i]+C+S[j];
				vis[j]=1;
				break;
			}
		}
		if(C.size()>R.size()) R=C;
	}
	
	cout<<R.size()<<endl;
	cout<<R<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}