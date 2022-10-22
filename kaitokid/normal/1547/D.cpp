#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[200009];
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
    for(int i=0;i<n;i++)cin>>x[i];
    cout<<0<<" ";
    for(int i=1;i<n;i++)
    {
        int d=(x[i-1]|x[i])^x[i];
        cout<<d<<" ";
        x[i]^=d;
    }
    cout<<endl;
}
    return 0;
}