// Hydro submission #62590c30cc64917dc4664407@1650003012897
#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int i,n,t=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        switch(s[0])
        {
            case 84:t+=4;break;
            case 67:t+=6;break;
            case 79:t+=8;break;
            case 68:t+=12;break;
            case 73:t+=20;break;
        }
    }
    printf("%d\n",t);
    return 0;
}