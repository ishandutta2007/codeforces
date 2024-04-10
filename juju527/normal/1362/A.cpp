#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int t;
	t=read();
	while(t--){
		long long a,b,ans=0;
		a=read();b=read();
		if(a>b)swap(a,b);
		if(b%a)ans=-1;
		long long k=b/a,cur=0;
		while(k%2==0)k/=2,cur++;
		if(k>1)ans=-1;
		if(ans==-1){printf("-1\n");continue;}
		printf("%lld\n",cur/3+(cur%3>0));
	}
	return 0;
}