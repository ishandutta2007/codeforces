// Hydro submission #625cecb4fa9408d417fea9c0@1650257081585
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l=s.size(),t=0,i;
    for(i=0;i<l;i++)
    if(s[i]==97) t++;
    printf("%d\n",t>l/2?l:2*t-1);
    return 0;
}