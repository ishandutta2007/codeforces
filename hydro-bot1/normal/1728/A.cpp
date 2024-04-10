// Hydro submission #631f306ebdf9bc31d15c837c@1662988398937
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,cnt,mx,p,i;
    cin>>t;
    while(t--)
    {
        cin>>n;mx=0,p=0;
        for(i=1;i<=n;i++)
        {
            cin>>cnt;
            if(cnt>mx)
            mx=cnt,p=i;
        }
        printf("%d\n",p);
    }
    return 0;
}