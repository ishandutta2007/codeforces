// Hydro submission #62677d149f31360077e12d0f@1650949397003
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,k,l,m;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s;m=0;
        l=s.size();
        for(j=0;j<l;j++)
        if(s[j]-48) m++;
        printf("%d\n",m);
        for(j=l-1;j+1;j--)
        if(s[j]-48)
        {
            printf(j-l+1?" %c":"%c",s[j]);
            for(k=0;k<l-j-1;k++)
            printf("0");
        }
        cout<<endl;
    }
    return 0;
}