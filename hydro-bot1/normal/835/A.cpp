// Hydro submission #62590d2737de167dd82bb28d@1650003239852
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,v1,v2,t1,t2,a,b;
    cin>>s>>v1>>v2>>t1>>t2;
    a=s*v1+2*t1;b=s*v2+2*t2;
    if(a<b) printf("First\n");
    else if(a>b) printf("Second\n");
    else printf("Friendship\n");
    return 0;
}