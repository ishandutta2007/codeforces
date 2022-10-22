#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++)a[i]=i;
       for(int i=n-1;i>=1;i-=2)swap(a[i],a[i+1]);
       for(int i=1;i<=n;i++)cout<<a[i]<<" ";
       cout<<endl;
    }
    return 0;
}