#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,t,f[200500],it;
ll l,r,n,m;
int cur,g[1005][1005];
struct sb{ll x,y,l;}s[200500];
vector<sb>v1[200500],v2[200500];

void add(sb &x){
	k=x.x+x.y;
	if(k>=500){
		for(ll j=i+x.x;j<=m;j+=k){
			l=j;r=min(m,l+x.y-1);
			f[l]++;f[r+1]--;
		}
	}
	else{
		g[k][(i+x.x)%k]++;
		g[k][i%k]--;
	}
	x.l=i;
}

void del(sb x){
	k=x.x+x.y;
	if(k>=500){
		for(ll j=x.l+x.x;j<=m;j+=k){
			l=j;r=min(m,l+x.y-1);
			f[l]--;f[r+1]++;
		}
	}
	else{
		g[k][(x.l+x.x)%k]--;
		g[k][x.l%k]++;
	}
	if(((i-x.l)%k)>=x.x)cur--;
}

int main() {
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&s[i].x,&s[i].y);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&it,&k);
		cur+=f[i];
		for(j=2;j<=500;j++)cur+=g[j][i%j];
		if(it==1) add(s[k]);
		else del(s[k]);
		printf("%d\n",cur);
	}
}