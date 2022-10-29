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
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,a[4][1001],cnt;
vector<pair<int,pii>> ans;
pii shift[4][1001],dis[4][1001];
void pre(){
    rep(i,0,n-1){
        shift[1][i]={1,i+1};
        dis[1][i+1]={1,i};
    }
    shift[1][n-1]={2,n-1};
    dis[2][n-1]={1,n-1};
    for(int i=n-1;i>0;i--){
        shift[2][i]={2,i-1};
        dis[2][i-1]={2,i};
    }
    shift[2][0]={1,0};
    dis[1][0]={2,0};
}
void rotate(pii d){
    rep(i,0,2*n){
        if(a[d.x][d.y]){
            ans.pb({a[d.x][d.y],shift[d.x][d.y]});
            a[shift[d.x][d.y].x][shift[d.x][d.y].y]=a[d.x][d.y];
            a[d.x][d.y]=0;
        }
        d=dis[d.x][d.y];
    }
}
void perform(){
    rep(i,0,n){
        if(a[0][i]==a[1][i] and a[0][i]){
            ans.pb({a[0][i],{0,i}});
            a[1][i]=0;
            cnt++;
        }
        if(a[3][i]==a[2][i] and a[2][i]){
            ans.pb({a[2][i],{3,i}});
            a[2][i]=0;
            cnt++;
        }
    }
}
void tr(){
    rep(i,0,4){
        rep(j,0,n){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void solve(){
    cin>>n>>k;
    rep(i,0,4){
        rep(j,0,n){
            cin>>a[i][j];
        }
    }
    pre();
    perform();
    while(1){
        int f1=0,f2=0;
        pii d;
        rep(i,0,n){
            if(a[1][i] || a[2][i]) f1=1;
            if(!a[1][i]){
                f2=1;
                d={1,i};
            }
            if(!a[2][i]){
                f2=1;
                d={2,i};
            }
        }
        if(f1){
            if(f2){
                rotate(d);
                perform();
            }
            else{
                cout<<-1<<endl;
                return;
            }
        }
        else break;
    }
    if(cnt==k){
        cout<<sz(ans)<<endl;
        rep(i,0,sz(ans)){
            cout<<ans[i].x<<" "<<ans[i].y.x+1<<" "<<ans[i].y.y+1<<endl;
        }
    }
    else{
        cout<<-1<<endl;
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