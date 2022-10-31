// Hydro submission #62ef212a74879b352565da31@1659838762589
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;cin>>a>>b;
    pair<int,int> c=minmax(a,b);
    printf("%d %d\n",c.first,(c.second-c.first)/2);
    return 0; 
}