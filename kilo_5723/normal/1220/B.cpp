#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=1e3+5;
ll a[maxn][maxn],b[maxn];
ll _sqrt(ll n){
    ll m=sqrt(n);
    while (m*m>n) m--;
    while (m*m<n) m++;
    return m;
}
int main(){
    int i,j,n;
    scanf("%d",&n);
    for (i=0;i<n;i++) for (j=0;j<n;j++) scanf("%I64d",&a[i][j]);
    b[0]=_sqrt(a[0][1]*a[0][2]/a[1][2]);
    b[1]=_sqrt(a[1][2]*a[1][0]/a[2][0]);
    b[2]=_sqrt(a[2][0]*a[2][1]/a[0][1]);
    for (i=3;i<n;i++) b[i]=a[i][i-1]/b[i-1];
    for (i=0;i<n;i++) printf("%I64d%c",b[i],i<n-1?' ':'\n');
    return 0;
}