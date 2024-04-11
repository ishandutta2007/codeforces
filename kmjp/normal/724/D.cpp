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

int M,L;
string S,R;
int pre[100100][26];
int did[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>S;
	L=S.size();
	
	FOR(x,26) pre[0][x]=-1;
	pre[0][S[0]-'a']=0;
	
	for(i=1;i<L;i++) {
		FOR(x,26) {
			pre[i][x]=pre[i-1][x];
			if(S[i]=='a'+x) pre[i][x]=i;
		}
	}
	
	
	vector<int> V;
	for(x=0;x+M<=L;) {
		FOR(i,26) {
			if(pre[x+M-1][i]>=x) break;
		}
		V.push_back(pre[x+M-1][i]);
		did[pre[x+M-1][i]]=1;
		x=pre[x+M-1][i]+1;
	}
	
	FORR(r,V) R+=S[r];
	sort(ALL(R));
	char la=R.back();
	FOR(i,L) if(did[i]==0 && S[i]<la) R.push_back(S[i]);
	sort(ALL(R));
	
	cout<<R<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}