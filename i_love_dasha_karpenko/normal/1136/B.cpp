#include <bits/stdc++.h>

using namespace std;
#define DIM 1007
#define INF 1000000000007
long long n,k,res,distl,distr;
int main()
{
    cin>>n>>k;
    distl = (k-1);
    distr = n-k;
    long long res = 3;
    res += min(distl,distr)*3;
    res+=min(distl,distr);
    res+=max(distl,distr)*3;

    cout<<res<<endl;
}