#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        if(n>m){cout<<"No"<<endl;continue;}
        if(((n%2)==0)&&(m%2)){cout<<"No"<<endl;continue;}
        cout<<"Yes"<<endl;
        if(n%2)
        {
            for(int i=1;i<n;i++)cout<<1<<" ";
            cout<<m-n+1<<endl;
            continue;
        }

        if((m%2)==0)
        {
            for(int i=0;i<n-2;i++)cout<<1<<" ";
            int u=(m-n+2)/2;
            cout<<u<<" "<<u<<endl;
            continue;
        }

    }
    return 0;
}