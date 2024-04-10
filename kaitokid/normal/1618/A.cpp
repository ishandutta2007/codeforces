#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[44];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<7;i++)cin>>a[i];
        if(a[0]+a[1]==a[2])cout<<a[0]<<" "<<a[1]<<" "<<a[3]<<endl;
        else cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    }
    return 0;
}