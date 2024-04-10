// Hydro submission #62591be5cc64917dc4664fe7@1650007014392
#include<bits/stdc++.h>
using namespace std;
bool f,g;
int main()
{
    int n,i;
    string s,b;
    cin>>s>>n;
    for(i=0;i<n;i++)
    {
        cin>>b;
        if(s==b)
        {
            printf("YES\n");
            return 0;
        }
        if(s[0]==b[1]) f=true;
        if(s[1]==b[0]) g=true;
    }
    if(f&&g) printf("YES\n");
    else printf("NO\n");
    return 0;
}