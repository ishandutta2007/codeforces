// Hydro submission #62ef1fd774296d3511bba65d@1659838423696
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int l=s2.size(),s=0,i;
    for(i=0;i<l;i++)
    if(s2[i]==s1[s]) s++;
    printf("%d\n",s+1);
    return 0;
}