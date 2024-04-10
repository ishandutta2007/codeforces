#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll l,r,p1,p2,p3,p4,num;
int main()
{
    cin>>p1>>p2>>p3>>p4>>l>>r;
    for(register int i=l;i<=r;i++)
    {
        if(i%p1%p2%p3%p4==i)
        {
            num++;
        }
    }
    cout<<num;
}