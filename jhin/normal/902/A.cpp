#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define fi first
#define ii pair<ll,ll>
#define se second
#define ld long double
#define mod 1000000007
using namespace std;

int n,m,s,e;
int main(){

   cin>>n>>m;
   vector <pair<int,int>>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i].fi>>a[i].se;
    sort(a.begin(),a.end());
    s=a[0].fi,e=a[0].se;
    for(int i=1;i<n;i++)
        if(a[i].fi<=e&&a[i].se>e)e=a[i].se;
        if(s==0&&e==m)cout<<"YES";
                 else cout<<"NO";
                 return 0;
}