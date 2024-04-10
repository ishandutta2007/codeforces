#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,T,a[maxn],is[3];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		is[0]=is[1]=0;
		for(i=1;i<=n;i++)a[i]=read()%2,is[a[i]]++;
		if(abs(is[0]-is[1])>1)puts("-1");
		else{
			ll ans=1e18,sum=0;
			int l[2]={1,2};
			for(i=1;i<=n;i++){
				if(l[a[i]]>n)sum=1e18;
				if(a[i])sum+=abs(i-l[a[i]]);
				l[a[i]]+=2;
			}
			ans=sum;sum=0;
			l[0]=2;l[1]=1;
			for(i=1;i<=n;i++){
				if(l[a[i]]>n)sum=1e18;
				if(a[i])sum+=abs(i-l[a[i]]);
				l[a[i]]+=2;
			}ans=min(ans,sum);
			printf("%lld\n",ans);
		}
	}
	return 0;
}