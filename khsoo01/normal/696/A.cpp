#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q;
vector<ll> cur;
map<ll, ll> val;

int main()
{
    scanf("%lld",&q);
    while(q--) {
        ll typ;
        scanf("%lld",&typ);
        if(typ == 1) {
            ll a, b, c;
            scanf("%lld%lld%lld",&a,&b,&c);
            cur.clear();
            while(a) {
                cur.push_back(a);
                a >>= 1;
            }
            while(b) {
                cur.push_back(b);
                b >>= 1;
            }
            sort(cur.begin(),cur.end());
            for(ll i=0;i<cur.size();i++) {
                if(i+1<cur.size() && cur[i]==cur[i+1]) i++;
                else val[cur[i]] += c;
            }
        }
        else {
            ll a, b;
            scanf("%lld%lld",&a,&b);
            cur.clear();
            while(a) {
                cur.push_back(a);
                a >>= 1;
            }
            while(b) {
                cur.push_back(b);
                b >>= 1;
            }
            sort(cur.begin(),cur.end());
            ll ret = 0;
            for(ll i=0;i<cur.size();i++) {
                if(i+1<cur.size() && cur[i]==cur[i+1]) i++;
                else ret += val[cur[i]];
            }
            printf("%lld\n",ret);
        }
    }
}