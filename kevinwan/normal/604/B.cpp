#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int k[100000];
int main() {
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",k+i);
    int ans=0;
    for(i=0;i<2*m-n&&n-1-i>=0;i++)ans=max(ans,k[n-i-1]);
    for(i=0;i<n-m;i++)ans=max(ans,k[i]+k[n*2-m*2-1-i]);
    printf("%d",ans);
}