#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll r=1,h=0;
        while(r<n && r<k)
        {
            r*=2;
            h++;
        }
       if(n>r)h+=(n-r+k-1)/k;
       cout<<h<<endl;
    }
    return 0;
}