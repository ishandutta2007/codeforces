#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        if(m==1 &&(k>0)){cout<<"NO\n";continue;}

        if((n%2)==0)
        {

            if((k%2)!=0){cout<<"NO\n";continue;}
            m-=(m%2);
            int r=(n*m)/2;
            if(r<k) cout<<"NO\n";
            else cout<<"YES\n";
            continue;
        }
            k=(n*m)/2-k;
            if(n==1 &&(k>0)){cout<<"NO\n";continue;}
            if((k%2)!=0){cout<<"NO\n";continue;}
            n-=(n%2);
            int r=(n*m)/2;
            if(r<k) cout<<"NO\n";
            else cout<<"YES\n";
            continue;

    }
    return 0;
}