#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n,a[10004]={0},b[100004],i;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i]>>b[i];
    for(i=0;i<n;++i)
    if(a[i]!=b[i]) {cout<<"rated";exit(0);}
    for(i=0;i<n-1;++i)
    if(a[i]<a[i+1]) {cout<<"unrated";exit(0);}
    cout<<"maybe";
    return 0;
}