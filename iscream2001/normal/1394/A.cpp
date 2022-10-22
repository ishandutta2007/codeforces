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
const int N=1e5+10;
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
int n,d;
LL m;
LL a[N],b[N];
int pa=0,pb=0;
bool cmp(LL A,LL B){
	return A>B;
}
int main(){
	cin>>n>>d>>m;
	LL x;
	for(int i=1;i<=n;++i) {
		scanf("%I64d",&x);
		if(x<=m) a[++pa]=x;
		else b[++pb]=x;
	}
	++d;
	sort(a+1,a+1+pa,cmp);
	sort(b+1,b+1+pb,cmp);
	for(int i=2;i<=n;++i) a[i]=a[i]+a[i-1];
	int y;LL ans=a[n],now=0;
	for(int i=1;i<=pb;++i){
		y=(i-1)*d+1;
		if(y>n) break;
		now+=b[i];
		ans=max(ans,now+a[n-y]);
	}
	
	cout<<ans<<endl;
	return 0;
}