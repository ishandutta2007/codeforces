#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define F first
#define S second
#define all(a) a.begin(),a.end()

using namespace std;

int main()
{
    long n,a[100005],i,u,l;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    i=0;
    while(a[i]==a[i+1]) i++;
    i++;
    l=i;
    i=n-1;
    while(a[i]==a[i-1]) i--;
    i--;
    u=i;
    if(u>=l) cout<<u-l+1;
    else cout<<0;
    return 0;
}