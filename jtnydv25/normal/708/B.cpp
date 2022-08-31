#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> myp;
const int maxn = 1e5;
int x[maxn];
int main()
{
    for(ll i = 1;(i*(i-1))/2 <=2e9;i++)
        myp[(i*(i-1))/2] = i;

    ll a0,a1,a2,a3;
    cin>>a0>>a1>>a2>>a3;
    ll n1 = myp[a0],n2 = myp[a3];
    // cout<<n1<<" "<<n2<<endl;
    if(n1==0 || n2==0)
    {
        cout<<"Impossible";// such n1,n2 don't exist
        return 0;
    }
    if(a1+a2==0)
    {
        string s;
        if(a3 == 0)
        {
            for(int i = 0;i<n1;i++)
                s+='0';
            cout<<s;
            return 0;
        }
        if(a0==0)
        {
            for(int i = 0;i<n2;i++)
                s+='1';
            cout<<s;
            return 0;
        }
        cout<<"Impossible";
        return 0;
    }
    if(a1+a2 != n1*n2)
    {
        cout<<"Impossible";
        return 0;
    }
    string s = "";
    int sm = 0;
    swap(a1,a2);
    for(int i = n1+1;i>=2;i--)
    {
        
        x[i] = a2/(i-1);
        a2 -= (i-1)*x[i];
        sm += x[i];
    }
    x[1] = n2 - sm;
    if(x[1]<0)
    {
        cout<<"Impossible";
        return 0;
    }
    for(int i = 1;i<=n1+1;i++)
    {
        for(int j = 0;j<x[i];j++)
            s+='1';
        if(i!=n1+1)
            s+='0';
    }
    assert(s.length() != 0);
    cout<<s;
    return 0;
}