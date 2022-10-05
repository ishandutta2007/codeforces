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

int N,M,Q;
int C[101010];
int in[101010],out[101010];
vector<int> H[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) C[i]=i;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		if(x>y) swap(x,y);
		in[x]++;
		out[y]++;
		H[x].push_back(y);
	}
	
	
	ll ret=0;
	FOR(i,N) ret+=1LL*in[i]*out[i];
	cout<<ret<<endl;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>x;
		x--;
		ret-=1LL*in[x]*out[x];
		out[x]+=in[x];
		in[x]=0;
		
		FORR(e,H[x]) {
			ret-=1LL*in[e]*out[e];
			in[e]++;
			out[e]--;
			ret+=1LL*in[e]*out[e];
			H[e].push_back(x);
		}
		H[x].clear();
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}