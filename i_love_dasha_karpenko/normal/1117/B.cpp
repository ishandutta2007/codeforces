#include <bits/stdc++.h>

using namespace std;
#define INF 100000000000007
#define DIM 100007
typedef pair<long long,long long> pairll;
long long n,m,k,mx=-INF,smx=-INF,res=0;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld %lld %lld\n",&n,&m,&k);
    for (int i = 1;i<=n;i++){
        long long x; scanf("%lld",&x);
        if (x>=mx){
            smx = mx;
            mx = x;
        }
        else if (smx<=x)smx = x;
    }
    long long h = m/(k+1);
    if (m%(k+1)!=0)res+=m%(k+1)*mx;
    //if (m%k==0)h++;
    res+=h*(mx*k+smx);
    printf("%lld\n",res);
}
//7+7+4+7+7+4+7+7+4