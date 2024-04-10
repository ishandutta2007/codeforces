// Hydro submission #62d79124cf4d7374b3eeb640@1658294565691
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,s,i;
    cin>>t;
    while(t--)
    {
        s=0;
        for(i=0;i<4;i++)
        cin>>a,s+=a;
        switch(s)
        {
            case 0:
            printf("0\n");
            break;
            case 4:
            printf("2\n");
            break;
            default:
            printf("1\n");
            break;
        }
    }
    return 0;
}