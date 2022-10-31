// Hydro submission #62590a09cc64917dc4664267@1650002446166
#include<bits/stdc++.h>
using namespace std;
string s,c="8xx3694705";
int main()
{
    cin>>s;
    int l=s.size(),i;
    for(i=0;i<=l/2;i++)
    if(s[l-i-1]!=c[s[i]-48])
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}