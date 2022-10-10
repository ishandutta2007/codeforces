#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=1010;
int i,j,k,n,m,T;ll a[maxn];
int main(){
	cin>>n;
	for(i=1;i<=n;i++)a[i]=read();
	ll ans=0;
	for(i=1;i<=n;i+=2){
		ll rsum=a[i],lsum=1;
		for(j=i+1;j<=n;j++){
			if(j%2==0){
				lsum-=a[j];
				rsum-=a[j];
				if(rsum<0){
					ans+=rsum-lsum+1;
//					cout<<"j="<<j<<" ans="<<ans<<endl;
					break;
				}
				if(lsum<=0)ans+=1-lsum;
//				cout<<"j="<<j<<" ans="<<ans<<endl;
				lsum=max(lsum,0ll);
			}
			else lsum+=a[j],rsum+=a[j];
		}//cout<<"i="<<i<<" ans="<<ans<<endl;
	}cout<<ans<<endl;
	return 0;
}