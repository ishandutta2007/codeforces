// Hydro submission #6295dfffb0c5e75beb144370@1653989376417
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,p,q,i;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>s,m=0;
        for(i=0;i<n;i++)
        if(s[i]=='A')
        {
            p=i+1,q=0;
            while(p<n&&s[p]=='P')
            p++,q++;
            m=max(m,q);
        }
        printf("%d\n",m);
    }
    return 0;
}