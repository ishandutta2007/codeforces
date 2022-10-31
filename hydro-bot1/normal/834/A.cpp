// Hydro submission #62590d15cc64917dc46644fb@1650003222348
#include<bits/stdc++.h>
using namespace std;
char v[4]={'<','^','>','v'};
bool cw,ccw;
int main()
{
    char a,b;int c,d,e,i;
    cin>>a>>b>>c;
    for(i=0;i<4;i++)
    {
        if(v[i]==a) d=i;
        if(v[i]==b) e=i;
    }
    if(v[(d+c)%4]==v[e]) cw=true;
    if(v[(e+c)%4]==v[d]) ccw=true;
    if(!(cw^ccw)) printf("undefined\n");
    else if(cw) printf("cw\n");
    else if(ccw) printf("ccw\n");
    return 0;
}