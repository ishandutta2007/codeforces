#include <bits/stdc++.h>

#define int         long long
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
int n,ans[100005];
vector<pair<int,pii>> v;
void solve(){
    unsigned long seed = mix(clock(), time(NULL), getpid());
    srand(seed);
    cin>>n;
    rep(i,0,n){
        ans[i]=1;
    }
    v.resize(n);
    rep(i,0,n){
        cin>>v[i].y.x>>v[i].y.y;
        v[i].x=i;
    }
    while(1){
        long double curx=0,cury=0;
        rep(i,0,n){
            if((curx+v[i].y.x)*(curx+v[i].y.x)+(cury+v[i].y.y)*(cury+v[i].y.y)<=(curx-v[i].y.x)*(curx-v[i].y.x)+(cury-v[i].y.y)*(cury-v[i].y.y)){
                ans[v[i].x]=1;
            }
            else{
                ans[v[i].x]=-1;
            }
            curx+=v[i].y.x*ans[v[i].x];
            cury+=v[i].y.y*ans[v[i].x];
        }
        if(curx*curx+cury*cury<=2e12){
            rep(i,0,n){
                cout<<ans[i]<<" ";
            }
            return;
        }
        random_shuffle(all(v));
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}