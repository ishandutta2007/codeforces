#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define sq(X) ((X)*(X))
#define INF 0x7fffffff
#define MAXN
using namespace std;
int a,b;
long double x;
double ans;

int main()
{
    ll i,j;
    scanf("%d%d",&a,&b);
    if(a<b) {
        printf("-1");
        return 0;
    }
    if(a==b) {
        printf("%lf",(double)a);
        return 0;
    }
    x=((long double)(a+b))/2;
    x/=(long double)((long long)(x/b));
    ans=x;
    printf("%.12lf",ans);
}