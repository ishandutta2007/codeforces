// Hydro submission #625504baac286d0a56b8576b@1649738938766
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,p,q,s=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>p>>q;
        if(q-p>1)
        s++;
    }
    printf("%d\n",s);
    return 0;
}