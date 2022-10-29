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
#define hell2       1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,bit[100005][2];
long double cnt,inv,upd;
void update(int in,int x){
    in++;
    while(in<=n+1){
        bit[in][0]+=x;
        bit[in][1]++;
        in+=in&(-in);
    }
}
pii query(int in){
    pii res={0,0};
    in++;
    while(in>0){
        res.x+=bit[in][0];
        res.y+=bit[in][1];
        in-=in&(-in);
    }
    return res;
}
void solve(){
    cin>>n;
    rep(i,1,n+1){
        int p;
        cin>>p;
        auto d=query(p);
        cnt+=1.0l*(i*(i-1)/2-d.x)*(n-i+1);
        inv+=i-1-d.y;
        update(p,i);
        upd+=1.0l*(n-i+1)*i*(i-1)/4;
    }
    cout<<fixed<<setprecision(10)<<inv+1.0l*(upd-cnt)/(n*(n+1)/2)<<endl;
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