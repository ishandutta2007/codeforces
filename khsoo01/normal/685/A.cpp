#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ac,bc,ans;
vector<ll> x,y;
ll ca[10005][8], cb[10005][8];

void validA(ll idx) {
    ll q[8], bu = idx;
    for(ll i=0;i<7;i++) q[i] = 0;
    for(ll i=0;i<ac;i++) {
        if(++q[idx%7]>1) return;
        idx /= 7;
    }
    for(ll i=0;i<7;i++) ca[x.size()][i] = q[i];
    x.push_back(bu);
}

void validB(ll idx) {
    ll q[8], bu = idx;
    for(ll i=0;i<7;i++) q[i] = 0;
    for(ll i=0;i<bc;i++) {
        if(++q[idx%7]>1) return;
        idx /= 7;
    }
    for(ll i=0;i<7;i++) cb[y.size()][i] = q[i];
    y.push_back(bu);
}

bool can(ll i, ll j) {
    for(ll k=0;k<7;k++) if(ca[i][k]+cb[j][k]>1) return false;
    return true;
}

int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<n;i*=7) ac++;
    for(ll i=1;i<m;i*=7) bc++;
    if(n==1) ac = 1;
    if(m==1) bc = 1;
    if(ac+bc>7) {
        puts("0"); return 0;
    }
    for(ll i=0;i<n;i++) {
        validA(i);
    }
    for(ll i=0;i<m;i++) {
        validB(i);
    }
    for(ll i=0;i<x.size();i++) {
        for(ll j=0;j<y.size();j++) {
            if(can(i,j)) ans++;
        }
    }
    printf("%lld",ans);
}