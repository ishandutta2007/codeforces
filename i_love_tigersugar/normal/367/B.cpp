#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
int m,n,p;
int a[MAX];
int b[MAX];
map<int,int> mp;
vector<int> res;
void init(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&p);
	FOR(i,1,n) scanf("%d",&a[i]);	
	FOR(i,1,m) scanf("%d",&b[i]);
}
void change(map<int,int> &mp,const int &key,const int &d) {
	mp[key]+=d;
	if (mp[key]==0) mp.erase(key);
}
void check(const int &f) {
	int cnt=0;
	for (int i=f;i<=n;i=i+p) cnt++;
	if (cnt<m) return;
	mp.clear();
	FOR(i,1,m) mp[b[i]]++;
	int cur=f;
	REP(i,m) {
		change(mp,a[cur],-1);
		cur+=p;		
	}	
	if (mp.empty()) res.push_back(f);
	for (int i=cur;i<=n;i=i+p) {
		change(mp,a[i-m*p],1);
		change(mp,a[i],-1);
		if (mp.empty()) res.push_back(i-(m-1)*p);
	}
}
void process(void) {
	FOR(i,1,p) check(i);
	printf("%d\n",res.size());
	sort(res.begin(),res.end());
	FORE(it,res) {
		if (it!=res.begin()) printf(" ");
		printf("%d",*it);
	}
}
int main(void) {
	init();
	process();
	return 0;
}