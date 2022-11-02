#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=3e5+5;
ll a[maxn];
int main(){
    int i,n,pos;
    ll ans;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%I64d",&a[i]);
    ans=0; pos=0;
    for (i=0;i<n;i++){
        ans+=a[i]/3;
        a[i]%=3;
        if (pos==i) pos++;
        while (a[i]&&pos<n){
            while (pos<n&&a[pos]<2) pos++;
            if (pos==n) break;
            ans++; a[i]--; a[pos]-=2;
        }
    }
    printf("%I64d",ans);
    return 0;
}