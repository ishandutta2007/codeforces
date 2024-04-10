#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long p,a,b,c;
        cin>>p>>a>>b>>c;
        cout<<min(min((p+a-1)/a*a-p,(p+b-1)/b*b-p),(p+c-1)/c*c-p)<<endl;
    }
    return 0;
}