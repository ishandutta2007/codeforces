// Hydro submission #6259228737de167dd82bd54f@1650008711430
#include<bits/stdc++.h>
using namespace std;
bool p,g,b,o,r,y;
int main()
{
    string s;
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        switch(s[0])
        {
            case 112:p=true;break;
            case 103:g=true;break;
            case 98:b=true;break;
            case 111:o=true;break;
            case 114:r=true;break;
            case 121:y=true;break;
        }
    }
    printf("%d\n",6-n);
    if(!p) printf("Power\n");
    if(!g) printf("Time\n");
    if(!b) printf("Space\n");
    if(!o) printf("Soul\n");
    if(!r) printf("Reality\n");
    if(!y) printf("Mind\n");
    return 0;
}