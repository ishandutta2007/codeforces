// Hydro submission #6253c1b8ca5306014671578b@1649656248832
#include<bits/stdc++.h>
using namespace std;
int l,s;
char c[1001];
int main()
{
    cin>>c+1;
    l=strlen(c+1);
    int i,j;
    for(i=2;i<=l;)
    {
        if(c[i]!='/'&&c[i-1]=='<')
        {
            for(j=1;j<=s;j++)
            printf(" ");
            printf("%c%c%c\n",c[i-1],c[i],c[i+1]);
            i+=3;s+=2;
        }
        else if(c[i]=='/')
        {
            s-=2;
            for(j=1;j<=s;j++)
			printf(" ");
            printf("</%c>\n",c[i+1]);
            i+=4;
        }
    }
    return 0;
}