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
string s;
int n;
int sol(string b){
    string a=s;
    int z=-1,o=-1,ans=0;
    for(int i=n-1;i>=0;i--){
        if(a[i]==b[1]){
            o=i;
            break;
        }
    }
    if(o==-1) return hell;
    rep(i,o,n-1){
        ans++;
        swap(a[i],a[i+1]);
    }
    for(int i=n-2;i>=0;i--){
        if(a[i]==b[0]){
            z=i;
            break;
        }
    }
    if(z==-1) return hell;
    rep(i,z,n-2){
        ans++;
        swap(a[i],a[i+1]);
    }
    if(a[0]=='0'){
        int f=-1;
        rep(i,0,n-2){
            if(a[i]!='0'){
                f=i;
                break;
            }
        }
        if(f==-1) return hell;
        ans+=f;
    }
    return ans;
}
void solve(){
    cin>>s;
    n=sz(s);
    if(n<2){
        cout<<-1<<endl;
        return;
    }
    int ans=hell;
    ans=min(ans,sol("00"));
    ans=min(ans,sol("25"));
    ans=min(ans,sol("50"));
    ans=min(ans,sol("75"));
    if(ans<hell){
        cout<<ans<<endl;
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