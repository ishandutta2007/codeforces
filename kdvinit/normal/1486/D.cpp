/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+1;

int n, k;
int a[N];

bool check(int x)
{
    int sumi=0;
    int sumj=0;
    int mnj=0;

    for(int i=1;i<=k;i++)
    {
        if(a[i]>=x) sumi++;
        else sumi--;
    }

    if(sumi>0) return true;

    for(int i=k+1;i<=n;i++)
    {
        if(a[i-k]>=x) sumj++;
        else sumj--;

        mnj=min(mnj,sumj);

        if(a[i]>=x) sumi++;
        else sumi--;

        int tmp=sumi-mnj;
        if(tmp>0)
        {
            //cout<<i<<" "<<tmp<<endl;
            return true;
        }
    }

    return false;
}

void solve()
{
   cin>>n>>k;

   for(int i=1;i<=n;i++) cin>>a[i];

   /*
   for(int i=1;i<=n;i++)
   {
       if(check(i)) cout<<i<<" "<<"True"<<endl;
       else cout<<i<<" "<<"False"<<endl;
   }
   */

   int l=1, r=n+1;
   while(l+1!=r)
   {
       int mid=(l+r)/2;
       if(check(mid)) l=mid;
       else r=mid;
   }

   cout<<l<<endl;
}

int32_t main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   solve();
   return 0;
}