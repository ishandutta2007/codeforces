// Hydro submission #62591d9c37de167dd82bc6c7@1650007453223
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    bool f=false;
    int t=0,i;
    for(i=0;i<s.size();i++)
    {
        if(!f&&s[i]==49) f=true;
        if(f&&s[i]==48) t++;
    }
    printf(t<6?"NO\n":"YES\n");
    return 0;
}