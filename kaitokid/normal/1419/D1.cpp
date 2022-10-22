#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[100008];
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    cout<<(n-1)/2<<endl;
int r=n-1,l=0;
while(r>l)
{
    cout<<a[r]<<" "<<a[l]<<" ";
    r--;
    l++;
}
if(l==r)cout<<a[r];
    return 0;
}