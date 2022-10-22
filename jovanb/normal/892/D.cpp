#include <bits/stdc++.h>

using namespace std;
long long a[22],b[22];
map <long long, long long> ind;
int main()
{
    long n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        ind[a[i]]=i;
    }
    sort(a,a+n);
    for(i=1;i<n;i++)b[ind[a[i]]]=a[i-1];
    b[ind[a[0]]]=a[n-1];
    for(i=0;i<n;i++)cout<<b[i]<<" ";
    return 0;
}