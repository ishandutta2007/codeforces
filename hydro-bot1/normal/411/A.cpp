// Hydro submission #6253dd7eca530601467182fc@1649663359526
#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int i,sn=0,sb=0,ss=0;
    cin>>s;
    if(s.size()<5)
    {
        printf("Too weak\n");
        return 0;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>47&&s[i]<58) sn++;
        if(s[i]>64&&s[i]<91) sb++;
        if(s[i]>98&&s[i]<123) ss++;
    }
    if(sn&&sb&&ss) printf("Correct\n");
    else printf("Too weak\n");
    return 0;
}