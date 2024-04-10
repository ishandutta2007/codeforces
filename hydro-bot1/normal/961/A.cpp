// Hydro submission #625920f637de167dd82bd12d@1650008354021
#include<bits/stdc++.h>
using namespace std;
int s[1000];
int main()
{
    int n,m,c,i,mn=1000;
    cin>>n>>m;
    for(i=0;i<m;i++)
    cin>>c,s[c-1]++;
    for(i=0;i<n;i++)
    if(s[i]<mn) mn=s[i];
    printf("%d\n",mn);
    return 0;
}