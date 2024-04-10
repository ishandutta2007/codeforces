// remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x,y,z;
    scanf("%I64d%I64d%I64d",&x,&y,&z);
    printf("%I64d %I64d\n",(x+y)/z,x%z+y%z>=z?z-max(x%z,y%z):0);
    return 0;
}