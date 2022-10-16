#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
const int s=1000000;
bool inx[MAX];
stack<int> fre,half,all;
vector<int> res;
void init(void) {
	int n;
	scanf("%d",&n);
	REP(i,n) {
		int v;
		scanf("%d",&v);
		inx[v]=true;
	}
	FOR(i,1,s/2) {
		int j=s+1-i;
		if (inx[i] && inx[j]) all.push(i);
		else if (!inx[i] && !inx[j]) fre.push(i);
		else half.push(i);
	}
	assert(fre.size()>=all.size());
	while (!half.empty()) {
		int u=half.top();half.pop();
		if (inx[u]) res.push_back(s+1-u); else res.push_back(u);
	}
	REP(zz,all.size()) {
		int u=fre.top();fre.pop();
		res.push_back(u);
		res.push_back(s+1-u);
	}
	sort(res.begin(),res.end());
	printf("%d\n",res.size());
	FORE(it,res) {
		if (it!=res.begin()) printf(" ");
		printf("%d",*it);
	}
}
int main(void) {
	init();
	return 0;
}