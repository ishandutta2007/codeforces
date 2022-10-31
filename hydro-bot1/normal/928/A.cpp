// Hydro submission #62591fea37de167dd82bce26@1650008042492
#include<bits/stdc++.h>
using namespace std;
string c(string x)
{
    for(int i=0;i<x.size();i++)
    {
        if(x[i]>96&&x[i]<123) x[i]-=32;
        if(x[i]==79) x[i]=48;
        if(x[i]==73||x[i]==76) x[i]=49;
    }
    return x;
}
int main()
{
    string x,y;int n,i;
    cin>>y>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(c(x)==c(y))
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}