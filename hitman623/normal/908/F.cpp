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
int n,ans;
vector<pair<int,char>> v;
map<char,int> l,r,f;
void solve(){
    l['G']=l['B']=l['R']=hell;
    cin>>n;
    rep(i,0,n){
        int p;
        char c;
        cin>>p>>c;
        v.pb({p,c});
        l[c]=min(l[c],p);
        r[c]=max(r[c],p);
        f[c]=1;
    }
    sort(all(v));
    if(f.count('B')) ans+=max(r['G'],r['B'])-min(l['G'],l['B']);
    if(f.count('R')) ans+=max(r['G'],r['R'])-min(l['G'],l['R']);
    int last_green=-3LL*hell,last_red=0,last_blue=0,red_max=0,blue_max=0,fr=0,fb=0;
    rep(i,0,sz(v)){
        if(v[i].y!='B'){
            red_max=max(red_max,v[i].x-last_red);
            last_red=v[i].x;
            if(v[i].y=='R') fr=1;
        }
        if(v[i].y!='R'){
            blue_max=max(blue_max,v[i].x-last_blue);
            last_blue=v[i].x;    
            if(v[i].y=='B') fb=1;
        }
        if(v[i].y=='G'){
            if(fr || fb) ans-=max(0LL,red_max+blue_max-v[i].x+last_green);
            else if(last_green>0){
                int q=1;
                if(f.count('R')) q--;
                if(f.count('B')) q--;
                ans+=q*(v[i].x-last_green);
            }
            last_green=v[i].x;
            red_max=blue_max=0;
            fr=fb=0;
        }
    }
    cout<<ans<<endl;
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