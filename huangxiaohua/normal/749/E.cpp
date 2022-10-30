#include <stdio.h>
typedef long long ll;

int i,j,k,t,m,a[100500];
ll b[100500],b2[100500],n,t1,t2;
double res;

void add(int x,int y){for(;x<=n;x+=(-x&x)){b[x]+=y;b2[x]++;}}
void get(int x,ll &r1,ll &r2){for(;x;x-=(-x&x)){r1+=b[x];r2+=b2[x];}}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		res+=0.25*i*(i-1)*(n+1-i);
		get(n+1-a[i],t1=0,t2=0);
		res+=1.0*(n*(n+1)/2*t2-(n-i+1)*t1);
		add(n+1-a[i],i);
	}
	printf("%.20lf",res/(n*(n+1)/2));
}