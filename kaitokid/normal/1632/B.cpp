#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        int mx=0;
        for(int i=0;i<20;i++)
            if(n>(1<<i))mx=(1<<i);
        for(int i=n-1;i>=mx;i--)cout<<i<<" ";
        for(int i=0;i<mx;i++)cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}