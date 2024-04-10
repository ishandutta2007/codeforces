#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(j-i<(n+1)/2)
                    cout<<"1 ";
                else if(n%2==0&&j-i==n/2)
                    cout<<"0 ";
                else    cout<<"-1 ";
        puts("");
    }
    return 0;
}