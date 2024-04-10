// Hydro submission #6253c5cdca53060146715f25@1649657293813
#include<bits/stdc++.h>
using namespace std;
int m[100000],s;
int main()
{
    int n,k,i,mn=1000000001;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m[i];
        if(m[i]<mn)
        {
            mn=m[i];
            k=i;
        }
    }
    for(i=0;i<n;i++)
    if(m[i]==mn) s++;
    if(s>1) printf("Still Rozdil\n");
    else printf("%d\n",k+1);
    return 0;
}