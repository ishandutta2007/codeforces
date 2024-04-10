#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int cntr=0,l=0,neg=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        char x;
        cin>>x;

        l++;
        if(x=='(') cntr++;
        else cntr--;

        if(cntr<0) neg=1;
        if(cntr==0)
        {
            if(neg==1) ans+=l;
            l=0;
            neg=0;
        }
    }

    if(cntr!=0) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}