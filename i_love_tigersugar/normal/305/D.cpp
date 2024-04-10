#include<cstdio>
#include<vector>
#include<cstdlib>
#include<algorithm>
#define MAX   1000100
using namespace std;
const int mod=(int)1e9+7;
int n,m,k;
vector<int> con;
int pw[MAX];
int min(const int &x,const int &y) {
	if (x<y) return (x); else return (y);
}
void init(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&k);
	int i,u,v;
	for (i=1;i<=m;i=i+1) {
		scanf("%d",&u);
		scanf("%d",&v);
		if (v-u==1) continue;
		if (v-u!=k+1) {
			printf("0");
			exit(0);
		}
		con.push_back(u);
	}
	if (con.empty()) return;
	sort(con.begin(),con.end());
	if (con[con.size()-1]-con[0]>k) {
		printf("0");
		exit(0);
	}
}
void precount(void) {
	int i;
	pw[0]=1;
	for (i=1;i<=k+3;i=i+1) pw[i]=(pw[i-1]<<1)%mod;
}
bool ok(const int &u) {
	if (con.empty()) return (true);
	return (u<=con[0] && con[con.size()-1]<=min(n-k-1,u+k));
}
int size(const int &u) {
	if (con.empty()) return (min(n-k-1,u+k)-u);
	int ret=min(n-k-1,u+k)-u-con.size();
	return (ret+(con[0]==u));
}
void count(void) {
	int res=con.empty();
	int i;
	for (i=1;i+k+1<=n;i=i+1)
		if (ok(i)) res=(res+pw[size(i)])%mod;
	printf("%d",res);
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	init();
	precount();
	count();
	return 0;
}