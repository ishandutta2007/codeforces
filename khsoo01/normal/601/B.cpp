#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

ll n, q, a[100005], d[100005];

struct data {ll p, v;};
stack<data> stk;

void solve () {
    ll A, B;
    scanf("%lld%lld",&A,&B); A++;
    ll ret = 0, cur = 0;
    while(!stk.empty()) stk.pop();
    stk.push({A-1, inf});
    for(int i=A;i<=B;i++) {
        while(!stk.empty()) {
            if(stk.top().v <= d[i]) {
                ll tmp = stk.top().v;
                ll idx = stk.top().p;
                stk.pop();
                cur -= tmp*(idx - stk.top().p);
            }
            else break;
        }
        cur += d[i]*(i - stk.top().p);
        stk.push({i, d[i]});
        ret += cur;
    }
    printf("%lld\n",ret);
}

int main()
{
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        d[i] = abs(a[i] - a[i-1]);
    }
    while(q--) solve();
}