#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll num,a,b,c,d;
int main()
{
    cin>>num;num++;
    for(;;num++)
    {
        a=num/1000;
        b=num/100%10;
        c=num/10%10;
        d=num%10;
        if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
        {
            cout<<num<<endl;
            break;
        }
    }
}