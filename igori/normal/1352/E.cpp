#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
vector<ll> V;
ll pre[maxn],sum[maxn],cnt[maxn];
bool has[maxn];
int main() {
    int T;cin>>T;
    while(T--){
        memset(has,0,sizeof has);
        memset(cnt,0,sizeof cnt);
        int n;cin>>n;for(int i=1;i<=n;i++) cin>>pre[i],sum[i]=sum[i-1]+pre[i],cnt[pre[i]]++;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i-1;j++){
                if(sum[i]-sum[j]<=n>=1&&sum[i]-sum[j]<=n&&!has[sum[i]-sum[j]]) {
                    has[sum[i]-sum[j]]=1;
                    ans+=cnt[sum[i]-sum[j]];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}