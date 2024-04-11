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
int P[101010];
int vis[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i], P[i]--;
	ll ret=0;
	vector<int> V;
	FOR(i,N) if(vis[i]==0) {
		int num=1;
		x=P[i];
		vis[i]=1;
		while(x!=i) {
			vis[x]=1;
			num++;
			x=P[x];
		}
		V.push_back(num);
	}
	
	sort(ALL(V));
	if(V.size()>1) {
		x=V.back();
		V.pop_back();
		V.back()+=x;
	}
	FORR(c,V) ret+=1LL*c*c;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}