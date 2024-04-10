#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll a,b,c,d,cnt,tot;
int main()
{
    cin>>a>>b>>c>>d>>cnt;
    for(register int i=1;i<=cnt;i++)
    {
        if(i%a==0||i%b==0||i%c==0||i%d==0)
        {
            tot++;
        }
    }
    cout<<tot<<endl;
}