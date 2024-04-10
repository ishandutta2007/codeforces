#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[55];
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
    bool bl=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)bl=false;
    }
    if(bl){cout<<0<<endl;continue;}
    if((a[1]==n)&&(a[n]==1)){cout<<3<<endl;continue;}
    if((a[1]==1)||(a[n]==n)){cout<<1<<endl;continue;}
    cout<<2<<endl;
}
    return 0;
}