// Hydro submission #62591b1d37de167dd82bc024@1650006828270
#include<bits/stdc++.h>
using namespace std;
string s[100];
int main()
{
    int n,i,j;
    bool f;
    cin>>n;
    for(i=0;i<n;i++)
    {
        f=true;
        cin>>s[i];
        for(j=0;j<i;j++)
        if(s[j]==s[i])
        {
            printf("YES\n");
            f=false;break;
        }
        if(f) printf("NO\n");
    }
    return 0;
}