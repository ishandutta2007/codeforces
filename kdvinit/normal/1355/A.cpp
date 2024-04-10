#include <iostream>
using namespace std;

int mn(long long int n)
{
    int mn1=10;
    while(n>0)
    {
        int x=n%10;
        mn1=min(mn1,x);
        if(mn1==0) break;
        n/=10;
    }
    return mn1;
}

int mx(long long int n)
{
    int mx1=0;
    while(n>0)
    {
        int x=n%10;
        mx1=max(mx1,x);
        if(mx1==9) break;
        n/=10;
    }
    return mx1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long int a,k;
        cin>>a>>k;
        k--;
        while(k>0)
        {
            if(mn(a)==0) break;
            a=a+mn(a)*mx(a);
            k--;
        }
        cout<<a<<endl;
    }
    return 0;
}