#include<cstdio>
#include<set>
#include<stack>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
set<int> unfull;
int cv[MAX],mv[MAX];
int n,q;
void init(void) {
	scanf("%d",&n);	
	FOR(i,1,n) scanf("%d",&mv[i]);
	FOR(i,1,n+1) unfull.insert(i);
}
void addwater(int u,int w) {
	set<int>::iterator it=unfull.lower_bound(u);
	int cur=*it;
	int rem=w;
	stack<int> st;
	while (!st.empty()) st.pop();
	while (cur<=n) {		
		if (cv[cur]+rem<mv[cur]) {
			cv[cur]+=rem;
			break;
		}
		st.push(cur);
		rem-=mv[cur]-cv[cur];
		cv[cur]=mv[cur];
		it++;
		cur=*it;
	}
	while (!st.empty()) {
		unfull.erase(st.top());
		st.pop();
	}	
}
void process(void) {
	scanf("%d",&q);
	REP(i,q) {
		int t,u,v;
		scanf("%d",&t);
		scanf("%d",&u);
		if (t>1) printf("%d\n",cv[u]);
		else {
			scanf("%d",&v);
			addwater(u,v);
		}
	}
}
int main(void) {
	init();
	process();
	return 0;
}