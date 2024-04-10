// Hydro submission #625909e137de167dd82bac30@1650002410901
#include<bits/stdc++.h>
using namespace std;
int h[16]={1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0};
int main()
{
    int n,s;cin>>n;
    s=!n;while(n)
    s+=h[n%16],n/=16;
    printf("%d\n",s);
    return 0;
}