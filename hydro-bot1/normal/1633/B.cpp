// Hydro submission #62972bdd1008115bd64b50e7@1654074333547
#include<bits/stdc++.h>
using namespace std;
int m[2];
int main()
{
    int t,l,i,j;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        m[0]=0,m[1]=0;
        cin>>s;
        l=s.size();
        for(j=0;j<l;j++)
        m[s[j]-48]++;
        printf("%d\n",m[0]-m[1]?min(m[0],m[1]):m[0]-1);
    }
    return 0;
}