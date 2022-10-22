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
    bool bl=false;
    int x;
    for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x<0)bl=true;
        }
        if(bl){cout<<"NO"<<endl;continue;}
        cout<<"YES"<<endl;
        cout<<101<<endl;
        for(int i=0;i<=100;i++)cout<<i<<" ";
        cout<<endl;
}
    return 0;
}