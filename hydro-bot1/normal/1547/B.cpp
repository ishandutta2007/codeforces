// Hydro submission #6274d695bda16328ffbb026f@1651824278190
#include<bits/stdc++.h>
using namespace std;
int m[26];
int main()
{
    string s;
    int t,l,mn,p,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s;
        l=s.size(),mn=127,p=l-1;
        for(j=0;j<26;j++) m[j]=0;
        for(j=0;j<l;j++)
        {
            if(s[j]<mn)
            {
                mn=s[j];
                p=j;
            }
            m[s[j]-97]++;
        }
        for(j=0;j<p;j++)
        if(s[j]<=s[j+1])
        {
            printf("NO\n");
            goto next;
        }
        for(j=p;j<l-1;j++)
        if(s[j]>=s[j+1])
        {
            printf("NO\n");
            goto next;
        }
        for(j=0;j<25;j++)
        if(m[j]>1||m[j]<m[j+1])
        {
            printf("NO\n");
            goto next;
        }
        printf("YES\n");
        next:;
    }
    return 0;
}