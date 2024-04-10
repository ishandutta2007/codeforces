#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n,m,p,x,y;
int head,tail,que[110000];
ll a[110000],s[110000],sum[110000],f[100005][105];
long double slope(int x,int y,int t){
	return (long double)(f[y][t]-f[x][t])/(y-x);
}
int main(){
    scanf("%d%d%d",&n,&m,&p);
    for (int i=2;i<=n;i++) scanf("%d",&x),s[i]=s[i-1]+x;
    for (int i=1;i<=m;i++) scanf("%d%d",&x,&y),a[i]=y-s[x];
    sort(a+1,a+m+1);
    for (int i=1;i<=m;i++) sum[i]=sum[i-1]+a[i];
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    for (int j=1;j<=p;j++){
        head=1; tail=1; que[1]=0;
        for (int i=1;i<=m;i++){
            while (head<tail&&slope(que[head],que[head+1],j-1)<=a[i]) head++;
            f[i][j]=(i-que[head])*a[i]+f[que[head]][j-1];
			while (head<tail&&slope(que[tail],i,j-1)<=slope(que[tail-1],que[tail],j-1)) tail--;
            que[++tail]=i;
        }
    }
    printf("%lld\n",f[m][p]-sum[m]);
    return 0;
}