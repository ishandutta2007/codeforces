#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int N=1e6+10;
const LL inf=1e18+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n;
LL r1,r2,r3,D;
LL a[N];
LL b[N][2];
LL f[N][2];
int main(){
	cin>>n>>r1>>r2>>r3>>D;
	for(int i=1;i<=n;++i) {
		scanf("%I64d",&a[i]);
		b[i][0]=min(r1,r3)*a[i]+r3;
		b[i][1]=r2+min(r1,min(r2,r3));
		b[i][1]=min(b[i][1],min(r1,r3)*a[i]+r1+min(r1,r3));
		b[i][1]=min(b[i][1],b[i][0]);
	}
	f[0][0]=f[0][1]=inf;f[0][0]=0;
	for(int i=1;i<=n;++i){
		f[i][0]=f[i][1]=inf;
		f[i][0]=min(f[i][0],min(f[i-1][0],f[i-1][1])+D+b[i][0]);
		f[i][1]=min(f[i][1],D+D+D+f[i-1][1]+b[i][1]);
		if(i-2>=0) f[i][1]=min(f[i][1],min(f[i-2][0],f[i-2][1])+b[i-1][1]+b[i][1]+D+D+D+D);
	}
	LL ans;
	ans=min(f[n][0],f[n][1]);
	LL now=min(b[n][0],b[n][1]+D+D)+D;
	for(LL i=n-1;i>=1;--i){
		ans=min(ans,min(f[i-1][0],f[i-1][1])+D+b[i][1]+now+D);
		now=now+D+D+b[i][1];
	}
	ans=ans-D;
	cout<<ans<<endl;
	return 0;
}