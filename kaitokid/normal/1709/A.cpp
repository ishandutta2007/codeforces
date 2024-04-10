#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        cin>>a[1]>>a[2]>>a[3];
        int ans=0;
        while(x!=0)
        {
            ans++;
            x=a[x];
        }
        if(ans==3)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


    }
    return 0;
}