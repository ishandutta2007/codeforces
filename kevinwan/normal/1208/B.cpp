#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e3+10;
int a[mn];
set<int>s;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,j;
    cin>>n;
    int ans=0x3f3f3f3f;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<=n;i++){
        s.clear();
        for(j=0;j<i;j++)s.insert(a[j]);
        if(s.size()!=i)break;
        ans=min(ans,n-i);
        for(j=n-1;j>=i;j--){
            if(s.find(a[j])!=s.end())break;
            ans=min(ans,j-i);
            s.insert(a[j]);
        }
    }
    printf("%d",ans);
}