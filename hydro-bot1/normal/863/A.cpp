// Hydro submission #62591b4437de167dd82bc13d@1650006852734
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l=s.size(),i,j;
    while(s[l-1]=='0') l--;
    for(i=0,j=l-1;i<l;i++,j--)
    if(s[i]-s[j])
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}