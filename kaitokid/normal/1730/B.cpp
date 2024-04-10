#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009],t[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        int mn=a[0],mx=a[0];
        for(int i=0;i<n;i++){cin>>t[i];mn=min(mn,a[i]-t[i]);mx=max(mx,a[i]+t[i]);}
        double ans=(mn+mx+0.0)/2.0;
        cout<<fixed<<setprecision(6)<<ans<<endl;



    }


    return 0;
}