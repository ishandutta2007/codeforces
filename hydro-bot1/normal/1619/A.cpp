// Hydro submission #62972a601008115bd64b4f9e@1654073957719
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,l,i,j;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s;
        l=s.size();
        if(l%2)
        {
            printf("NO\n");
            continue;
        }
        else
        {
            for(j=0;j<l/2;j++)
            if(s[j]!=s[j+l/2])
            {
                printf("NO\n");
                goto next;
            }
            printf("YES\n");
            next:;
        }
    }
    return 0;
}