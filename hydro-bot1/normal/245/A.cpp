// Hydro submission #6253c93e48f7830132792066@1649658174881
#include<bits/stdc++.h>
using namespace std;
int x1,x2,y1,y2;
int main()
{
    int n,t,x,y,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t>>x>>y;
        if(t-2)
        {
            x1+=x;
            y1+=y;
        }
        else
        {
            x2+=x;
            y2+=y;
        }
    }
    printf(x1<y1?"DEAD\n":"LIVE\n");
    printf(x2<y2?"DEAD\n":"LIVE\n");
    return 0;
}