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
int n,ans1,ans2,ans3;
mi f1,f2,f3;
string s1,s2,s3;
void solve(){
    cin>>n>>s1>>s2>>s3;
    int m=sz(s1);
    rep(i,0,m){
        f1[s1[i]]++;
        f2[s2[i]]++;
        f3[s3[i]]++;
    }
    for(auto i:f1){
        if(n==1 and i.y==m){
            ans1=m-1;
        }
        else{
            ans1=max(ans1,min(m,i.y+n));
        }
    }
    for(auto i:f2){
        if(n==1 and i.y==m){
            ans2=m-1;
        }
        else{
            ans2=max(ans2,min(m,i.y+n));
        }
    }
    for(auto i:f3){
        if(n==1 and i.y==m){
            ans3=m-1;
        }
        else{
            ans3=max(ans3,min(m,i.y+n));
        }
    }
    if(ans1>ans2 and ans1>ans3){
        cout<<"Kuro"<<endl;
        return;
    }
    if(ans2>ans1 and ans2>ans3){
        cout<<"Shiro"<<endl;
        return;
    }
    if(ans3>ans1 and ans3>ans2){
        cout<<"Katie"<<endl;
        return;
    }
    cout<<"Draw"<<endl;
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