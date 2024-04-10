#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
inline ll read(){
	char c=getchar();ll x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=500010;
int i,j,k,n,m,a[maxn],l[maxn],r[maxn],lans[maxn],rans[maxn],Ans[maxn];
int find(int now,int S){
	if(now==0)return 0;
	if(a[now]>=S)return find(l[now],S);
	else return now;
}
int Find(int now,int S){
	if(now==n+1)return n+1;
	if(a[now]>=S)return Find(r[now],S);
	else return now;
}
signed main(){
	cin>>n;
	for(i=1;i<=n;i++)a[i]=read();
	l[1]=0;r[n]=n+1;
	for(i=2;i<=n;i++){
		if(a[i]>a[i-1])l[i]=i-1;
		else l[i]=find(i-1,a[i]);
	}
	for(i=n-1;i>=1;i--){
		if(a[i]>a[i+1])r[i]=i+1;
		else r[i]=Find(i+1,a[i]);
	}
	for(i=1;i<=n;i++){
		ll ans=(i-l[i])*a[i]+lans[l[i]];
		lans[i]=ans;
	}
	for(i=n;i>=1;i--){
		ll ans=(r[i]-i)*a[i]+rans[r[i]];
		rans[i]=ans;
	}
	ll ans1=-1e15,ans2;
	for(i=1;i<=n;i++){
		if(lans[i]+rans[i]-a[i]>ans1){
			ans1=lans[i]+rans[i]-a[i];
			ans2=i;
		}
		//cout<<i<<' '<<l[i]<<' '<<r[i]<<' '<<lans[i]<<' '<<rans[i]<<' '<<a[i]<<endl; 
	}
	Ans[ans2]=a[ans2];
	ll last=a[ans2];
	for(i=ans2-1;i>=1;i--){
		last=min(last,a[i]);
		Ans[i]=last;
	}last=a[ans2];
	for(i=ans2+1;i<=n;i++){
		last=min(last,a[i]);
		Ans[i]=last;
	}last=a[ans2];
	for(i=1;i<=n;i++)
		printf("%lld ",Ans[i]);
	cout<<endl;
	return 0;
}