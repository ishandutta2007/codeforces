#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[3000],b[3000],n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool ans=true;
        for(int i=1;i<=n;i++)
        {cin>>a[i];
        if((a[i]%2)!=(i%2))ans=false;}
        if(!ans){cout<<-1<<endl;continue;}
        cout<< 5*(n/2)<<endl;

        for(int i=(n/2);i>0;i--)
        {
            int u=2*i+1,v=2*i;
            for(int j=1;j<=n;j++){if(u==a[j]){cout<<j<<" "; reverse(a+1,a+j+1);break;} }
            for(int j=1;j<=n;j++){if(v==a[j]){cout<<j-1<<" ";reverse(a+1,a+j);cout<<j+1<<" ";reverse(a+1,a+j+2);break;}}
            cout<<3<<" "<<u<<" ";
            reverse(a+1,a+4);

            reverse(a+1,a+u+1);


        }
        cout<<endl;
    }
    return 0;
    }