#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll num;
int main()
{
    cin>>num;//eh
    for(register int i=sqrt(num);i>=1;i--)
    {
        if(num/i==(double)(num)/i)
        {
            cout<<i<<" "<<num/i<<endl;
            return 0;
        }
    }
}