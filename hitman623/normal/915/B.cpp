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
void solve()
{
    int n,pos,l,r;
    cin>>n>>pos>>l>>r;
    if(l==1){
        if(r==n){
            cout<<0;
        }
        else cout<<abs(r-pos)+1;
    }
    else {
        if(r==n){
            cout<<abs(pos-l)+1;
        }
        else cout<<min(abs(pos-l)+1+abs(r-l)+1,abs(r-pos)+1+abs(r-l)+1);
    }
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