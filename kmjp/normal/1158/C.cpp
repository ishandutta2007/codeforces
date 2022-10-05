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

int T,N;
int nex[501010];
int la[501010];
vector<int> tar[501010];
int ret[501010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for(i=1;i<=N+1;i++) la[i]=i,tar[i].clear();
		for(i=1;i<=N;i++) {
			scanf("%d",&nex[i]);
			if(nex[i]==-1) nex[i]=i+1;
			tar[la[nex[i]]].push_back(i);
			la[nex[i]]=i;
		}
		deque<int> D;
		for(i=1;i<=N;i++) {
			while(D.size()&&D.front()==i) D.pop_front();
			if(D.size()&&D.front()<nex[i]) {
				_P("-1\n");
				break;
			}
			D.push_front(nex[i]);
		}
		if(i<=N) continue;
		
		int cur=N+1;
		queue<int> Q;
		Q.push(N+1);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			
			ret[x]=cur--;
			FORR(t,tar[x]) Q.push(t);
		}
		assert(cur==0);
		for(i=1;i<=N;i++) _P("%d ",ret[i]);
		_P("\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}