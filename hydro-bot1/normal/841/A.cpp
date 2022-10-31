// Hydro submission #62591adecc64917dc4664f80@1650006750327
#include<bits/stdc++.h>
using namespace std;
int t[26];
int main()
{
    int n,k,i;char s;
    cin>>n>>k;
    for(i=0;i<n;i++)
    cin>>s,t[s-97]++;
    for(i=0;i<26;i++)
    if(t[i]>k)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}