#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n;
int main()
{

    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%4!=0){cout<<"NO\n";continue;}
        cout<<"YES\n";
        vector<int>a,b;
        n/=4;
        for(int i=0;i<n;i++)cout<<2+i*6<<" ";
        for(int i=0;i<n;i++)cout<<4+i*6<<" ";

        for(int i=0;i<n;i++)cout<<(1+(i*6))<<" ";
        for(int i=0;i<n;i++)cout<<(5+(i*6))<<" ";
    cout<<endl;
    }

    return 0;
}