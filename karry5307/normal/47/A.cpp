#include<bits/stdc++.h>
using namespace std;
typedef int ll;
bool tri[50000];
ll num,tot;
int main()
{
    for(register int i=0;tot<=500;i++)
    {
       tot+=i;
       tri[tot]=1;
    }
    cin>>num;
    tri[num]?cout<<"YES"<<endl:cout<<"NO"<<endl;
}