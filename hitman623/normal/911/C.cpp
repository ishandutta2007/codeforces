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
    int k[3];
    cin>>k[0]>>k[1]>>k[2];
    sort(k,k+3);
    if(k[0]==1 || k[1]==2 || (k[2]==3 && k[1]==3 && k[0]==3) || (k[2]==4 && k[1]==4 && k[0]==2))
        cout<<"YES";
    else cout<<"NO";
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