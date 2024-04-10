#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m;
int a[1002],b[102],s1,s2;
int main()
{
cin>>n>>m;
for(int i=0;i<n;i++){cin>>a[i];s1^=a[i];}
for(int i=0;i<m;i++){cin>>b[i];s2^=b[i];}
    if(s1!=s2){cout<<"NO";return 0;}
    cout<<"YES\n";
    for(int i=0;i<n-1;i++)
    {
        for(int i=0;i<m-1;i++)cout<<0<<" ";
        cout<<a[i]<<endl;
        }
        for(int i=0;i<m-1;i++)cout<<b[i]<<" ";
        cout<<(s1^b[m-1]^a[n-1]);
    return 0;
}