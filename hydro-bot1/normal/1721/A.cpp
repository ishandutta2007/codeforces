// Hydro submission #631f2f23bdf9bc31d15c8106@1662988067255
#include<bits/stdc++.h>
using namespace std;
bool f[26];
int main()
{
    int t,s,i;
    char c;
    cin>>t;
    while(t--)
    {
        memset(f,false,sizeof(f));
        s=-1;for(i=0;i<4;i++)
        {
            cin>>c;c-=97;
            if(!f[c])
            f[c]=true,s++;
        }
        printf("%d\n",s);
    }
    return 0;
}