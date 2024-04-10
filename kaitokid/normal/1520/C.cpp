#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==2){cout<<-1<<endl;continue;}
        int d=1;
        for(int i=1;i<=n*n;i++)
        {cout<<d<<" ";
        if((i%n)==0)cout<<endl;
        d+=2;
        if(d>n*n)d=2;
        }


    }
    return 0;
}