// Hydro submission #6274cb33997df5291339cd93@1651821364243
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,l,i;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s;
        l=s.size();
        printf("%d\n",(l+1)*l/2+10*(s[0]-49));
    }
    return 0;
}