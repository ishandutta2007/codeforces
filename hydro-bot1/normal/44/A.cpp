// Hydro submission #6247f846993deab65610788d@1648883783776
#include<bits/stdc++.h>
using namespace std;
string s1[101],s2[101];
int main()
{
    int n,i,j,m=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s1[i]>>s2[i];
        m++;
        for(j=i-1;j>=0;j--)
        if(s1[i]==s1[j]&&s2[i]==s2[j])
        {
            m--;
            break;
        }
    }
    printf("%d\n",m);
    return 0;
}