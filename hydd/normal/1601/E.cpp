#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,k,a[310000];
int head,tail,que[310000];
int val[310000],nxt[310000];
ll Val[21][310000]; int Nxt[21][310000];
int main(){
	scanf("%d%d%d",&n,&q,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	head=1; tail=0;
	for (int i=1;i<=n;i++){
		while (head<=tail&&a[que[tail]]>=a[i]) tail--;
		que[++tail]=i;
		while (head<=tail&&que[head]<i-k) head++;
		val[i]=a[que[head]];
	}
	Nxt[0][n+1]=n+1;
	for (int i=n;i>=1;i--){
		nxt[i]=i+k;
		while (nxt[i]<=n&&val[nxt[i]]>=val[i]) nxt[i]=nxt[nxt[i]];
		
		Nxt[0][i]=min(nxt[i],n+1);
		Val[0][i]=1ll*val[i]*((nxt[i]-i)/k);
	}
	for (int j=1;j<20;j++)
		for (int i=1;i<=n+1;i++){
			Nxt[j][i]=Nxt[j-1][Nxt[j-1][i]];
			Val[j][i]=Val[j-1][i]+Val[j-1][Nxt[j-1][i]];
		}
	int l,r;
	while (q--){
		scanf("%d%d",&l,&r);
		ll ans=a[l]; l+=k; r++;
		if (l>r){ printf("%lld\n",ans); continue;}
		for (int i=19;i>=0;i--)
			if (Nxt[i][l]<=r){
				ans+=Val[i][l];
				l=Nxt[i][l];
			}
		ans+=1ll*val[l]*((r-l-1+k)/k);
		printf("%lld\n",ans);
	}
	return 0;
}