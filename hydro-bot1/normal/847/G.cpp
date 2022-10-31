// Hydro submission #62591af6cc64917dc4664f8a@1650006774821
#include<bits/stdc++.h>
using namespace std;
int t[7],mx;
int main()
{
    int n,i,j;
    string s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        for(j=0;j<7;j++)
        if(s[j]==49) t[j]++;
    }
    for(i=0;i<7;i++)
    mx=max(t[i],mx);
    printf("%d\n",mx);
    return 0;
}