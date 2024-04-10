#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, l, v1, v2, k, c;

bool can (double T) {
    double timeleft = T, cur = 0;
    for(ll i=0;i<c;i++) {
        if(v1*timeleft>=l-cur) return true;
        double tgap = (double)(l-cur-v1*timeleft)/(v2-v1);
        if(tgap*v2+cur>l) return false;
        if(i==c-1) return true;
        tgap *= (1+(double)(v2-v1)/(v2+v1));
        cur += tgap*v1;
        timeleft -= tgap;
        if(timeleft<0) return false;
    }
    return true;
}

int main()
{
    scanf("%lld%lld%lld%lld%lld",&n,&l,&v1,&v2,&k);
    c = (n+k-1)/k;
    double S = 0, E = 1e9;
    for(int i=0;i<100;i++) {
        if(can((S+E)/2)) E = (S+E)/2;
        else S = (S+E)/2;
    }
    printf("%.12f\n",S);
}