// Hydro submission #6274cc6e997df5291339d065@1651821679046
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,l,i;
    cin>>t;
    string s;
    for(i=0;i<t;i++)
    {
        cin>>s;
        l=s.size();
        printf(l%2==0&&s[0]-41&&s[l-1]-40?"YES\n":"NO\n");
    }
    return 0;
}