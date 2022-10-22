#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int a[mn];
int main(){
    #ifdef LOCAL
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
    #endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    stack<pii>av,th;
    vector<pii>ans;
    for(int i=n;i>=1;i--){
        if(a[i]==1){
            ans.push_back({i,i});
            av.push({i,i});
        }
        else if(a[i]==2){
            if(av.empty()){
                printf("-1\n");
                return 0;
            }
            pii p=av.top();
            av.pop();
            ans.push_back({i,p.second});
            th.push({i,p.second});
        }
        else if(a[i]==3){
            if(av.empty()&&th.empty()){
                printf("-1\n");
                return 0;
            }
            pii p=th.size()?th.top():av.top();
            th.size()?th.pop():av.pop();
            th.push({i,i});
            ans.push_back({i,i});
            ans.push_back({p.first,i});
        }
    }
    printf("%d\n",ans.size());
    for(pii p:ans)printf("%d %d\n",p.second,p.first);
}