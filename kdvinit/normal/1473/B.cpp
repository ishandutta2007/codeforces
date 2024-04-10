/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a,int b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

void solve()
{
    string s,t;
    cin>>s>>t;

    int n=s.size();
    int m=t.size();

    int l,k;
    for(l=1;l<=n;l++)
    {
        if(n%l!=0) continue;
        int pos=1;
        for(int i=0;i<l;i++)
        {
            if(pos==0) break;
            int j=i;
            while(j<n)
            {
                if(s[j]!=s[i]) pos=0;
                j+=l;
            }
        }
        if(pos==1) break;
    }

    for(k=1;k<=m;k++)
    {
        if(m%k!=0) continue;
        int pos=1;
        for(int i=0;i<k;i++)
        {
            if(pos==0) break;
            int j=i;
            while(j<m)
            {
                if(t[j]!=t[i]) pos=0;
                j+=k;
            }
        }
        if(pos==1) break;
    }

    if(l!=k) { cout<<-1<<endl; return; }

    for(int i=0;i<l;i++)
    {
        if(s[i]!=t[i]) { cout<<-1<<endl; return; }
    }

    int x=n/l;
    int y=m/k;

    int z=(x*y)/(gcd(x,y));

    while(z--)
    {
        for(int i=0;i<l;i++) cout<<s[i];
    }
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}