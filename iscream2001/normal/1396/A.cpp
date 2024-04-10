#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
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
LL n; 
LL a[N],b[N],c[N];
int main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;++i) scanf("%I64d",&a[i]);
	if(n==1){
		cout<<1<<" "<<1<<endl;
		printf("%I64d\n",-a[1]);
		cout<<1<<" "<<1<<endl;
		cout<<0<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<0<<endl;
		return 0;
	}
	cout<<1<<" "<<1<<endl;
	printf("%I64d\n",-a[1]);
	a[1]=0;
	LL x=n-1,y;
	for(LL i=1;i<n;++i){
		b[i]=x*i%n;
		c[b[i]]=-i;
	}
	c[0]=0;
	cout<<2<<" "<<n<<endl;
	for(int i=2;i<=n;++i){
		y=(a[i]%n+n)%n;
		printf("%I64d ",x*c[y]);
		a[i]=a[i]+x*c[y];
	}
	puts("");
	cout<<1<<" "<<n<<endl;
	for(int i=1;i<=n;++i){
		printf("%I64d ",-a[i]);
	}
	puts("");
	return 0;
}