// Hydro submission #62550d0dac286d0a56b86ab9@1649741083464
#include<bits/stdc++.h>
using namespace std;
int m[50],t,p;
int main()
{
    int i,n;char s;
    cin>>n; 
    for(i=0;i<n;i++)
    {
        cin>>s;
        if(s==66) t++;
        else if(t) m[p]=t,t=0,p++;
    }
    if(t) m[p]=t,p++;
    printf("%d\n",p);
    for(i=0;i<p;i++)
    printf("%d ",m[i]);
    cout<<endl;
    return 0;
}