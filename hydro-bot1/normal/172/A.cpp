// Hydro submission #6253c4beca53060146715c93@1649657022731
#include<bits/stdc++.h>
using namespace std;
char s[21],c[21];
int main()
{
    int t,i,j,n;
    cin>>n>>s;
    t=strlen(s);
    for(i=1;i<n;i++)
    {
        cin>>c;
        for(j=0;j<t;j++)
        if(s[j]!=c[j])
        break;
        t=j;
    }
    printf("%d\n",t);
    return 0;
}