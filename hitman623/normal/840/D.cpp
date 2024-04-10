#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define hell2       1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
#include <unistd.h> // not included in bits/stdc++.h
#define int long
unsigned int mix(unsigned int a, unsigned int b, unsigned int c)
#undef int
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}
int n,q,b[300005],vis[300005],c[300005];
vi a[300005];
void solve(){
    unsigned long seed = mix(clock(), time(NULL), getpid());
    srand(seed);
    cin>>n>>q;
    rep(i,1,n+1){
        int x;
        cin>>x;
        b[i]=x;
        a[x].emplace_back(i);
    }
    rep(i,0,q){
        int l,r,k;
        cin>>l>>r>>k;
        int s=(r-l+1)/k+1;
        int ans=hell,cnt=0;
        rep(_,0 ,80){
            int x=l+(rand()*rand())%(r-l+1);
            if(sz(a[b[x]])<s || vis[b[x]]) continue;
            vis[b[x]]=1;
            c[cnt++]=b[x];
            int f=upper_bound(all(a[b[x]]),r)-lower_bound(all(a[b[x]]),l);
            if(f>=s){
                ans=min(ans,b[x]);
            }
        }
        rep(j,0,cnt){
            vis[c[j]]=0;
        }
        if(ans<hell) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}