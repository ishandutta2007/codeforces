#include<bits/stdc++.h>
#define MAX   100100
using namespace std;
int h[MAX];
int f[MAX];
int lg2[MAX];
int rmqx[MAX][19];
int rmqn[MAX][19];
int n,q;
vector<int> res;
int max(const int &x,const int &y) {
	if (x>y) return (x); else return (y);
}
int min(const int &x,const int &y) {
	if (x<y) return (x); else return (y);
}
void init(void) {
	scanf("%d",&n);
	scanf("%d",&q);
	int i;
	for (i=1;i<=n;i=i+1) scanf("%d",&h[i]);
}
void setup_rmq(void) {
	int i,j;
	for (i=1;i<=n;i=i+1) {
		rmqx[i][0]=h[i];
		rmqn[i][0]=h[i];
	}
	for (i=1;i<=n;i=i+1) {
		while ((1<<lg2[i])<=i) lg2[i]++;
		lg2[i]--;
	}
	for (j=1;j<=17;j=j+1)
		for (i=1;i+(1<<j)-1<=n;i=i+1) {
			rmqx[i][j]=max(rmqx[i][j-1],rmqx[i+(1<<(j-1))][j-1]);
			rmqn[i][j]=min(rmqn[i][j-1],rmqn[i+(1<<(j-1))][j-1]);
		}			
}
int delta(const int &i,const int &j) {
	int k=lg2[j-i+1];
	int minv=min(rmqn[i][k],rmqn[j-(1<<k)+1][k]);
	int maxv=max(rmqx[i][k],rmqx[j-(1<<k)+1][k]);
	return (maxv-minv);
}
void process(void) {
	int i,l,m,r;
	int ans=0;
	for (i=1;i<=n;i=i+1) {
		l=1;
		r=n-i+1;
		while (true) {
			if (l==r) {
				m=r;
				break;
			}
			if (r-l==1) {
				if (delta(i,i+r-1)<=q) m=r;
				else m=l;
				break;
			}
			m=(l+r)/2;
			if (delta(i,i+m-1)<=q) l=m;
			else r=m-1;
		}
		f[i]=m;
		ans=max(ans,m);
	}
	for (i=1;i<=n;i=i+1)
		if (f[i]==ans) res.push_back(i);
	printf("%d %d\n",ans,res.size());
	for (i=0;i<res.size();i=i+1) printf("%d %d\n",res[i],res[i]+ans-1);	
}
int main(void) {
	init();
	setup_rmq();
	process();
	return 0;
}