#include<bits/stdc++.h>
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
    int mx=0,id=1;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>mx){mx=x;id=i;}
    }
    cout<<id<<endl;
    }
    return 0;
}