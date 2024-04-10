#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e3+5;
int a[maxn];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int i,j,n,h;
    ll ans;
    scanf("%d%d",&n,&h);
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    for (i=0;i<n;i++){
        for (j=i;j>0;j--) if (a[j]>a[j-1])
            swap(a[j],a[j-1]);
        ans=0;
        for (j=0;j<=i;j+=2) ans+=a[j];
        if (ans>h){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("%d\n",n);
    return 0;
}