#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        for(int i=31;i>=0;i--)
        {
            if(n&(1<<i)){cout<<(1<<i)-1<<endl;break;}
        }
    }
}