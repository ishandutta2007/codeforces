#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=2e5+10;

int a[mn],h[mn],ans[mn];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n,m,x;
        cin>>n>>m>>x;
        for(int i=0;i<n;i++)cin>>a[i];
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int i=0;i<m;i++)pq.push({h[i]=0,i});
        for(int i=0;i<n;i++){
            int x=pq.top().second;
            pq.pop();
            ans[i]=x+1;
            h[x]+=a[i];
            pq.push({h[x],x});
        }
        printf("YES\n");
        for(int i=0;i<n;i++)printf("%d ",ans[i]);
        printf("\n");
    }
}