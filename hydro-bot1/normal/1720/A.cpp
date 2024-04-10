// Hydro submission #631f2e5e32ae6c3198c90c4d@1662987871739
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,d,x,y;
    int t;cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        x=a*d,y=b*c;
        if(x==y) printf("0\n");
        else if(x&&y%x==0||y&&x%y==0)
        printf("1\n");
        else printf("2\n");
    }
    return 0;
}