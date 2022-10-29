#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
    long long n,i,a[100005],s=0,p[100005]={0};
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        if(i>0)
        p[i]=a[i]+p[i-1];
        else p[i]=a[i];
        s+=a[i];
    }
    if(s%2) {cout<<"NO";exit(0);}
    if(binary_search(p,p+n,s/2)) {cout<<"YES";exit(0);}
    for(i=0;i<n;++i)
    {
        if(binary_search(p+i+1,p+n,s/2+a[i])) {cout<<"YES";exit(0);}
        if(binary_search(p,p+i,s/2-a[i])) {cout<<"YES";exit(0);}
    }
    cout<<"NO";
    return 0;
}