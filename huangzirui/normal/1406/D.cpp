#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=100010;
ll i,j,k,n,m,T,a[maxn],d[maxn];
ll sum[2];
int main(){
	cin>>n;
	for(i=1;i<=n;i++)a[i]=read(),d[i]=a[i]-a[i-1],sum[d[i]>0]+=abs(d[i]);
	cin>>m;
	ll s=(sum[1]+(d[1]<0?d[1]:0));
	printf("%lld\n",(s+(s>0))/2);
	for(i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		sum[d[x]>0]-=abs(d[x]);
		d[x]+=z;
		sum[d[x]>0]+=abs(d[x]);
		if(y!=n){
			sum[d[y+1]>0]-=abs(d[y+1]);
			d[y+1]-=z;
			sum[d[y+1]>0]+=abs(d[y+1]);
		}
		ll s=(sum[1]+(d[1]<0?d[1]:0));
		printf("%lld\n",(s+(s>0))/2);
	}
}