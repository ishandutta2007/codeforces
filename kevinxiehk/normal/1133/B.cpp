#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int cnt[m+5];
    for(int i=0;i<=m;i++){
        cnt[i]=0;
    }
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        cnt[t%m]++;
    }
    int ans=0;
    ans+=cnt[0]/2*2;
    if(m%2==0)ans+=cnt[m/2]/2*2;
    for(int i=1;i<=m/2;i++){
        if(m%2==0&&i==m/2)break;
        ans+=min(cnt[i],cnt[m-i])*2;
    }
    cout<<ans<<endl;
    return 0;
}