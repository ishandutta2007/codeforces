#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t;
ll a[200500],sb[200500],b[200500],f[200500],c[200500],tmp,ans,nmsl[200500];
bool vis[200500];

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>sb[i];
		b[a[i]]+=sb[i];
		nmsl[a[i]]+=sb[i];
	}
	for(i=1;i<=20;i++){
		memset(c,0,sizeof(c));
		for(j=1;j<=200000;j++){
			c[a[j]]+=min(i,sb[j]);
		}
		sort(c+1,c+200000+1);
		for(j=1;j<=i;j++){
			f[i]+=c[200000+1-j];
		}
	}
	sort(b+1,b+200000+1);
	for(i=1;i<=20;i++){
		tmp+=b[200000+1-i];
	}
	for(i=21;i<=n;i++){
		tmp+=b[200000+1-i];
		f[i]=tmp;
	}
	ans=0;
	for(i=1;i<=n;i++){
		if(i==1||(f[ans]*i)<(f[i]*ans)){
			ans=i;
		}
		//printf("a%d %d\n",i,f[i]);
	}
	cout<<ans<<'\n';
	k=ans;
	if(ans<=20){
		memset(nmsl,0,sizeof(nmsl));
		memset(b,0,sizeof(b));
		for(j=1;j<=n;j++){
			b[a[j]]+=min(ans,sb[j]);
			nmsl[a[j]]+=min(ans,sb[j]);
		}
		sort(b+1,b+200000+1);
	}
	for(i=1;i<=200000;i++){
		if(nmsl[i]>b[200000+1-ans]){
			cout<<i<<' ';
			k--;
		}
	}
	for(i=1;i<=200000;i++){
		if(k&&nmsl[i]==b[200000+1-ans]){
			cout<<i<<' ';
			k--;
		}
	}
}