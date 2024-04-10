/* bread
  _______
   /       )
  /_____   | ______
 (  '   ) / /    __\   _____
  |.  '| / |     \ |  /     ))
  |____|/  |`-----'  /_____))
            \`-----'  `------' */
#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    int n;
    cin>>n;
    int cnt[4];
    for(int i=0;i<3;i++)cnt[i]=0;
    int aa;
    for(int i=0;i<n;i++){
        cin>>aa;
        cnt[aa%3]++;
        
    }
    int ans=min(cnt[1],cnt[2]);
        cnt[1]-=ans;
        cnt[2]-=ans;
        ans+=cnt[1]/3;
        ans+=cnt[2]/3;
        ans+=cnt[0];
    cout<<ans<<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}