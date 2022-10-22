#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+10;
const int INF=2e9;
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
int n,k;
int cnt=0;
LL a[N],b[N];
priority_queue<LL> Q;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int now=n;
	LL x=0,ans=0;
	while(now>=1&&a[now]>=0){
		ans+=x;x+=a[now];--now;
	}
	while(now>=1&&x>=0){
		ans+=x;x+=a[now];--now;
	}
	b[0]=x;int j=0;
	while(now>=1){
		++j;
		if(j>k) j=0;
		ans+=b[j];
		b[j]+=a[now];
		--now;
	}
	printf("%lld\n",ans);
	return 0;
}