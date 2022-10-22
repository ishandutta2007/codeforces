#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool bl=false;
        for(int i=2;i<(sqrt(n)+1);i++)
        {
            if(n%i==0){bl=true;int d=(n/i);cout<<d<<" "<<n-d<<endl;break;}
        }
        if(!bl)cout<<1<<" "<<n-1<<endl;
    }
    return 0;

}