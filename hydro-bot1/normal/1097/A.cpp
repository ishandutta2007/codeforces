// Hydro submission #625cebda81ef68d42bcbad28@1650256859572
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a,b,c,d;
    cin>>a>>b;
    for(int i=0;i<5;i++)
    {
        cin>>c>>d;
        if(c==a||d==b)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}