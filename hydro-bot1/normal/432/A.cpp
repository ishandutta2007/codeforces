// Hydro submission #6254fda817cd4d0a41763cfd@1649737128469
#include<bits/stdc++.h>
using namespace std;
int y[2000],s;
int main()
{
    int n,k,i;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>y[i];
        if(y[i]<=5-k)
        s++;
    }
    printf("%d\n",s/3);
    return 0;
}