// Hydro submission #629728ba1008115bd64b4e5a@1654073531470
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,i,j;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>s;m=0;
        for(j=0;j<n;j++)
        {
            m+=s[j]-48;
            if(j<n-1&&s[j]-48) m++;
        }
        printf("%d\n",m);
    }
    return 0;
}