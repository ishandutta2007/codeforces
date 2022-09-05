#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2e5+5,D=1e9+7;
int n,a[N];

int main()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
    int ans=0;
    rep(i,1,n)ans+=a[n]-a[i];
    printf("%d\n",ans);
    //printf("%d\n",n);
}