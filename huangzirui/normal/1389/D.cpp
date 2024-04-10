#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
ll i,j,k,n,m,sum,is;
ll l[2],r[2];
int main(){
	int T;T=read();
	while(T--){
		ll ans=0;
		sum=0;is=0;
		n=read();m=read();
		l[0]=read(),r[0]=read();
		l[1]=read(),r[1]=read();
		if(l[0]>l[1])swap(l[0],l[1]),swap(r[0],r[1]);
		if(r[0]>=l[1]){
			if(r[0]>=r[1])swap(r[0],r[1]);
			sum+=n*(r[0]-l[1]);
			if(sum>=m){
				printf("0\n");
				continue;
			}else{
				for(i=1;i<=n;i++){
					if(sum+r[1]-r[0]+l[1]-l[0]>=m){
						printf("%lld\n",ans+(m-sum));
						sum=-1;
						break;
					}
					sum+=r[1]-r[0]+l[1]-l[0];ans+=r[1]-r[0]+l[1]-l[0];
				}
				if(sum<0)continue;
				printf("%lld\n",ans+(m-sum)*2);
			}
		}else{
			for(i=1;i<=n;i++){
				ll useful=min(m-sum,r[1]-l[0]),pay=l[1]-r[0]+min(m-sum,r[1]-l[0]);
				if(i!=1 && pay>=useful*2)break;
				ans+=l[1]-r[0];
				if(sum+r[1]-l[0]>=m){
					printf("%lld\n",ans+(m-sum));
					sum=-1;
					break;
				}
				sum+=r[1]-l[0];ans+=r[1]-l[0];
			}
			if(sum<0)continue;
			printf("%lld\n",ans+(m-sum)*2);
		}
	}
	return 0;
}