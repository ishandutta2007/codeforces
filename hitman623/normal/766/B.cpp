#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()

using namespace std;

int main()
{
    ll n,a[100005]={0},i,mi,ma,hi,lo;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    for(i=1;i<n-1;++i)
    {
        if(a[i-1]+a[i]>a[i+1]) {cout<<"YES";exit(0);}
    }
    cout<<"NO";
    return 0;
}