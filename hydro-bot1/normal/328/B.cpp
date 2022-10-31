// Hydro submission #6253d1b4ca53060146716ff6@1649660341560
#include<bits/stdc++.h>
using namespace std;
int s[10],t[10];
int main()
{
    int i,mn=10000;
    string a,b;
    cin>>a>>b;
    for(i=0;i<a.size();i++) s[a[i]-48]++;
    for(i=0;i<b.size();i++) t[b[i]-48]++;
    s[6]+=s[9],s[2]+=s[5];
    t[6]+=t[9],t[2]+=t[5];
    for(i=0;i<10;i++) if(s[i]>0&&i!=5&&i!=9)
    mn=min(t[i]/s[i],mn);
    printf("%d\n",mn);
    return 0;
}