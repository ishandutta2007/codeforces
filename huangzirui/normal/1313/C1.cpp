#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	char c=getchar();ll x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=1010; 
ll i,j,k,n,m,a[maxn],ans[maxn],now[maxn];
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
		a[i]=read();
	for(i=1;i<=n;i++){
		ll last=a[i];
		k=a[i];
		now[i]=a[i];
		for(j=i-1;j>=1;j--){
			now[j]=min(last,a[j]);
			k+=min(last,a[j]);
			last=min(last,a[j]);
		}last=a[i];
		for(j=i+1;j<=n;j++){
			now[j]=min(last,a[j]);
			k+=min(last,a[j]);
			last=min(last,a[j]);
		}
		if(k>m){
			for(j=1;j<=n;j++)
				ans[j]=now[j];
			m=k;
		}
	}
	for(i=1;i<=n;i++)
		cout<<ans[i]<<' ';cout<<endl;
	return 0;
}