// Hydro submission #631f3013bdf9bc31d15c82a8@1662988308259
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        printf(x<y&&(x==1||x<4&&y>3)?"NO\n":"YES\n"); 
    }
    return 0;
}