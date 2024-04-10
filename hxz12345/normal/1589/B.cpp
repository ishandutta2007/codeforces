#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long Testing,n,m,ans;
int main(){
	Testing=read();
	for (;Testing;Testing--){
		n=read();m=read();
		//1*33*1
		ans=(n/3)*m;
		n=n % 3;
		ans=ans+(m/3)*n;
		m=m % 3;
		if ((n==2)&&(m==2)) ans+=2;
		else if (min(n,m)!=0) ans+=1;
		printf("%lld\n",ans);
	}
return 0;
}