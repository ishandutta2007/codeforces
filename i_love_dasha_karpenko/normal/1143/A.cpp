#include <bits/stdc++.h>

using namespace std;
#define DIM 1007
#define INF 1000000000000000007
long long lastr,lastl,n;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld\n",&n);
    for (int i = 1;i<=n;i++){
        long long x; scanf("%lld",&x);
        if (x==0){
            lastl = i;
        }
        else{
            lastr = i;
        }
    }
    printf("%lld\n",min(lastl,lastr));
}