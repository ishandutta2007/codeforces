#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int inf=0x3f3f3f3f;
const int mn=1e6+10;
int a[mn];
int main(){
    int n;
    string s;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>s;
    for(int i=1;i<=n;i++)a[i]=(s[i-1]=='('?1:-1);
    int cur=0,bs=-1,ans=0;
    for(int i=1;i<=n;i++){
        cur+=a[i];
        if(cur<0){
            if(bs==-1)bs=i;
        }
        else{
            if(bs!=-1){
                ans+=i-bs+1;
                bs=-1;
            }
        }
    }
    if(cur)printf("-1");
    else printf("%d",ans);
}