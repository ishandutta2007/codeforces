#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,mx[1000005];
bool np[1000005];

vector<pair<int,int> > fac;

int main()
{
    scanf("%lld%lld",&n,&k);
    ll tmp = k;
    for(ll i=2;i*i<=k;i++) {
        if(tmp%i==0) {
            ll cnt = 0;
            while(tmp%i==0) {
                tmp /= i;
                cnt++;
            }
            fac.push_back({i,cnt});
        }
    }
    if(tmp!=1) fac.push_back({tmp,1});
    for(ll i=0;i<n;i++) {
        ll cur;
        scanf("%lld",&cur);
        for(int j=0;j<fac.size();j++) {
            if(cur%fac[j].first==0) {
                ll cnt = 0;
                while(cur%fac[j].first==0) {
                    cur /= fac[j].first;
                    cnt++;
                }
                mx[j] = max(mx[j], cnt);
            }
        }
    }
    for(int i=0;i<fac.size();i++) {
        if(fac[i].second>mx[i]) {
            puts("No"); return 0;
        }
    }
    puts("Yes");
}