#include <bits/stdc++.h>

using namespace std;
long long n,a[3009],u;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    cout<<n+1<<endl;
    for(int i=n;i>0;i--)
    {
        a[i]+=u;
        long long x=((i-1)-(a[i]%n)+n)%n;
        if(x==0)x=n;
        cout<<"1 "<<i<<" "<<x<<endl;
        u+=x;


    }
    cout<<"2 "<<n<<" "<<n<<endl;
    return 0;
}