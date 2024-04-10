// Hydro submission #625ceb02fa9408d417fea8df@1650256642719
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long l,r,i;
    cin>>l>>r;
    printf("YES\n");
    for(i=l;i<r;i+=2)
    printf("%lld %lld\n",i,i+1);
    return 0;
}