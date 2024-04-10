#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define _(x)(x&-x)
using namespace std;
const int N=2e5+5;
int n,t[N],wz[N],tt;
ll an,ans,x[N],y[N],z;
struct no{int x,y;}a[N];
bool cmp(no x,no y){return x.x<y.x;}
int qu(int x){int s=0;for(;x;x-=_(x))s+=t[x];return s;}
void ch(int x){for(;x<=n<<1;x+=_(x))t[x]++;}
int main(){
	scanf("%d",&n);an=(ll)n*(n-1)*(n-2)/6;
	fo(i,1,n){
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
		wz[a[i].x]=-i;wz[a[i].y]=i;
	}
	fo(i,1,n*2)if(wz[i]<0){
		int w=-wz[i];
		ch(a[w].y);
		y[w]=qu(a[w].y);
		x[w]=i-y[w];
	}else{
		int w=wz[i];
		y[w]=++tt-y[w];
	}
	tt=0;
	fd(i,1,n*2)if(wz[i]>0)x[wz[i]]+=tt;else tt++;
	fo(i,1,n)z=n-1-x[i]-y[i],an-=x[i]*y[i],ans-=(x[i]+y[i])*z;
	printf("%I64d",an+(ans>>1));
}