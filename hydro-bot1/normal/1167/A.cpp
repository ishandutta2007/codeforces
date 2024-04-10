// Hydro submission #625ced07fa9408d417feaa5d@1650257159871
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i,j;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>s;
        if(n<11)
        printf("NO\n");
        else
        {
            for(j=0;j<=n-11;j++)
            if(s[j]==56)
            {
                printf("YES\n");
                goto next;
            }
            printf("NO\n");
            next:;
        }
    }
    return 0;
}