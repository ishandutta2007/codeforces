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
ll i,j,k,n,m,T,a[maxn];
int main(){
	cin>>T;
	while(T--){
		n=read();m=read();
		for(i=1;i<=n;i++)a[i]=read();
		double l=0,r=m,ti=0;ll now1=0,now2=n;
		while(1){
			if(now1==now2){
				printf("%.8f\n",ti+(r-l)/(2+n));
				break;
			}if((a[now1+1]-l) * (n-now2+1)>(r-a[now2]) * (1+now1)){
				double T=(r-a[now2])/(n-now2+1);
				ti+=T;
				r=a[now2];l+=T*(1+now1);
				now2--;
			}else{
				double T=(a[now1+1]-l)/(1+now1);
				ti+=T;
				l=a[now1+1];r-=T*(n-now2+1);
				now1++;
			}
		}
	}
	return 0;
}