/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,s;
const int N=2e5+1;
const int mxp=1e15;

int smin[N];
int smax[N];



bool pos(int x)
{
    int m=n/2;
    int mnl=0;
    // Hello RVK :)

    vector<int> givethem;
    for(int i=1; i<=n;i++)
    {
        if(smax[i]<x) mnl++;
        else givethem.push_back(smin[i]);
    }

    if(mnl>m) return false;
    sort(givethem.begin(),givethem.end());

    int tmp=s;
    int gs=givethem.size();
    for(int i=gs-m-1; i<gs;i++)
    {
        if(givethem[i]>x) break;
        else
        {
            tmp-=(x-givethem[i]);
        }
    }

    if(tmp<0) return false;
    else return true;
}

void solve()
{
    cin>>n>>s;

    for(int i=1;i<=n;i++) { cin>>smin[i]>>smax[i]; s-=smin[i]; }

    /*
    int t; cin>>t;
    while(t--) { int x; cin>>x; cout<<pos(x)<<endl; }
    return;
    */

    int l=1,r=mxp; // l is always possible, r is always impossible
    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(pos(mid)) l=mid;
        else r=mid;
    }

    cout<<l<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}