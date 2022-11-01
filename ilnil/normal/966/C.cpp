#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define db long double
using namespace std;
const int N=1e5+5;
int n,la[61],ne[N];
ll to[N],x,a[N],y,u[N];
bool b;
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n){
		scanf("%I64d",&u[i]);
	}
	sort(u+1,u+n+1);
	fo(i,1,n){
		x=u[i];
		fd(j,0,59)if(x&((ll)1<<j)){
			ne[i]=la[j];la[j]=i;to[i]=x;break;
		}
	}
	fo(i,0,59)if(la[i]){
		x=to[la[i]];la[i]=ne[la[i]];
		break;
	}
	a[1]=x;b=1;
	fo(i,2,n){
		b=0;
		fo(j,0,59)if(la[j]&&!(x&((ll)1<<j))){
			y=to[la[j]];x^=y;b=1;la[j]=ne[la[j]];
			break;
		}
		a[i]=y;
		if(!b)break;
	}
	if(b){
		printf("Yes\n");
		fo(i,1,n)printf("%I64d ",a[i]);
	}else printf("No");
}