#include <bits/stdc++.h>
using namespace std;

int main()
{
    map < vector < long > , int > mp;
    long long n,k,x,mx=0,mn=100005,i,j=2,y;
    cin>>n>>k>>x;
    vector < long > a;
    for(i=0;i<n;++i)
    {cin>>y;
    a.push_back(y);}
    sort(a.begin(),a.end());
    mp[a]=1;
    while(j<=k+1)
    {
        for(i=0;i<n;i+=2)
        a[i]^=x;
        sort(a.begin(),a.end());
        if(mp[a]) {k-=mp[a]-1;k%=j-mp[a];j=1;mp.clear();}
        mp[a]=j;
        j++;
    }
    cout<<a[n-1]<<" "<<a[0];
    return 0;
}