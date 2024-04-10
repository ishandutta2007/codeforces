#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=2e5+10;
int d[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",d+i);
    sort(d+1,d+1+n);
    int dis=n/2;
    int ans=0x3f3f3f3f;
    for(int i=1;i+dis<=n;i++)ans=min(ans,d[i+dis]-d[i]);
    printf("%d",ans);
}