// Hydro submission #62550462ac286d0a56b856ba@1649738850703
#include<bits/stdc++.h>
using namespace std;
string s[8]={"vaporeon",
    "jolteon","flareon",
    "espeon","umbreon",
    "leafeon","glaceon",
    "sylveon"
},c;
int main()
{
    int i,j,l;
    cin>>l>>c;
    for(i=0;i<8;i++)
    if(s[i].size()!=l) continue;
    else for(j=0;j<l;j++)
    {
        if(j==l-1)
        {
            cout<<s[i];
            return 0;
        }
        if(c[j]!='.'&&c[j]!=s[i][j])
        break;
    }
    return 0;
}