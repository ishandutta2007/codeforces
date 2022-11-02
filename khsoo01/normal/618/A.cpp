#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,s=1<<24;

int main()
{
    ll i,j,k;
    scanf("%lld",&n);
    for(k=25;s>0;s>>=1,k--) {
        if(s&n) printf("%lld ",k);
    }
}