#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int u=(n-1)/2;
        if(k>u){cout<<-1<<endl;continue;}
    cout<<1<<" ";
    int r=2;
    while(k)
    {
        cout<<r+1<<" "<<r<<" ";
        k--;
        r+=2;
    }
    while(r<=n){cout<<r<<" ";r++;}
    cout<<endl;
    }
    return 0;
}