#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=2e5+10;
int a[mn];
bool vis[mn];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)vis[i]=0;
        for(int i=0;i<n;i++)scanf("%d",a+i),a[i]+=i,a[i]%=n,a[i]+=n,a[i]%=n,vis[a[i]]=1;
        bool ans=1;
        for(int i=0;i<n;i++)ans&=vis[i];
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
}