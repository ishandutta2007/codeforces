#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi             map<int,int>
#define mii            map<int,pii>    
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)    for(int i=a;i<b;i++)
using namespace std;
int n,k,v[505][505],b[250005],cur=1,cnt;
char a[505][505];
void dfs(int x,int y){
    if(v[x][y] || a[x][y]=='X') return;
    v[x][y]=cur;
    cnt++;
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x,y-1);
}
int f[250005]={0},x=0,curans=0,ans=0;
void solve()
{
    cin>>n>>k;
    rep(i,0,n+2){
        rep(j,0,n+2){
            if(i==0 || j==0 || i==n+1 || j==n+1) a[i][j]='X';
            else cin>>a[i][j];
        }
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            if(!v[i][j] && a[i][j]=='.'){
                cnt=0;
                dfs(i,j);
                b[cur]=cnt;
                cur++;
            }
        }
    }
    rep(i,1,k+1){
        rep(j,1,k+1){
            if(a[i][j]=='X') x++;
        }
    }
    rep(i,0,k+2){
        rep(j,(i==0 || i==k+1),k+2-(i==0 || i==k+1)){
            if(a[i][j]=='.'){
                f[v[i][j]]++;
                if(f[v[i][j]]==1) curans+=b[v[i][j]];   
            }
        }
    }
    ans=max(ans,curans+x);
    rep(i,0,n-k+1){
        int tempans=curans,tempx=x,tempf[cur+1];
        rep(j,0,cur+1)
        tempf[j]=f[j];
        rep(j,0,n-k){
            rep(l,1,k+1){
                if(a[i+l][j+k+1]=='X') x++;
                if(a[i+l][j+1]=='X') x--;
            }
            rep(l,0,k+2){
                if(a[i+l][j+k+2-(l==0 || l==k+1)]=='.'){
                    f[v[i+l][j+k+2-(l==0 || l==k+1)]]++;
                    if(f[v[i+l][j+k+2-(l==0 || l==k+1)]]==1) curans+=b[v[i+l][j+k+2-(l==0 || l==k+1)]];
                }
                if(a[i+l][j+(l==0 || l==k+1)]=='.'){
                    f[v[i+l][j+(l==0 || l==k+1)]]--;
                    if(f[v[i+l][j+(l==0 || l==k+1)]]==0) curans-=b[v[i+l][j+(l==0 || l==k+1)]];
                }
            }
            ans=max(ans,curans+x);
        }
        curans=tempans;
        x=tempx;
        rep(j,0,cur+1)
        f[j]=tempf[j];
        rep(l,1,k+1){
            if(a[i+k+1][l]=='X') x++;
            if(a[i+1][l]=='X') x--;
        }
        rep(l,0,k+2){
            if(a[i+k+2-(l==0 || l==k+1)][l]=='.'){
                f[v[i+k+2-(l==0 || l==k+1)][l]]++;
                if(f[v[i+k+2-(l==0 || l==k+1)][l]]==1) curans+=b[v[i+k+2-(l==0 || l==k+1)][l]];
            }
            if(a[i+(l==0 || l==k+1)][l]=='.'){
                f[v[i+(l==0 || l==k+1)][l]]--;
                if(f[v[i+(l==0 || l==k+1)][l]]==0) curans-=b[v[i+(l==0 || l==k+1)][l]];
            }
        }
        if(i==n-k) break;
        ans=max(ans,curans+x);
    } 
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)
        solve();
    return 0;
}