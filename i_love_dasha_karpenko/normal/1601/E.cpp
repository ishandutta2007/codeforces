#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 3e5+7;
ll T[N*2],mod[N*2];
void push(int t, int tl, int tr) {
    int tm = (tl + tr) >> 1;
    int l = t + 1, r = t + ((tm - tl + 1) << 1);
    T[l] += mod[t] * (tm - tl + 1);
    T[r] += mod[t] * (tr - tm);
    mod[l] += mod[t];
    mod[r] += mod[t];
    mod[t] = 0;
}

void update(int t, int tl, int tr, int l, int r, ll val) {
    if (tl > r || l > tr)
        return;
    if (l <= tl && tr <= r) {
        T[t] += val * (tr - tl + 1);
        mod[t] += val;
        return;
    }
    push(t, tl, tr);
    int tm = (tl + tr) >> 1;
    update(t + 1, tl, tm, l, r, val);
    update(t + ((tm - tl + 1) << 1), tm + 1, tr, l, r, val);
    T[t] = T[t + 1] + T[t + ((tm - tl + 1) << 1)];
}

ll get(int t, int tl, int tr, int l,int r) {
    if (tl > r || tr < l)
        return 0;
    if (l<=tl && tr<=r)
        return T[t];
    push(t, tl, tr);
    int tm = (tl + tr) >> 1;
    return get(t + 1, tl, tm, l,r) + get(t + ((tm - tl + 1) << 1), tm + 1, tr, l,r);
}

int A[N];
vector<pair<int,int> > Q[N];
ll ans[N];
int n,q,k,mt[N*2];
void buildtree(int t,int tl,int tr){
    if (tl==tr){
        mt[t] = A[tl];
        return;
    }
    int tm = (tl+tr)>>1;
    buildtree(t+1,tl,tm);
    buildtree(t+((tm-tl+1)<<1),tm+1,tr);
    mt[t] = min(mt[t+1],mt[t+((tm-tl+1)<<1)]);
}
const int INF = 1e9;
int get_min(int t,int tl,int tr,int l,int r){
    if (tl>r || l>tr)
        return INF;
    if (l<=tl && tr<=r)
        return mt[t];
    int tm = (tl+tr)>>1;
    return min(get_min(t+1,tl,tm,l,r),get_min(t+((tm-tl+1)<<1),tm+1,tr,l,r));
}
int pos(int val,int mod){
    return (val-mod)/k;
}
void solve(){

    cin>>n>>q>>k;
    for(int i = 1;i<=n;++i)
        cin>>A[i];

    for(int i = 1;i<=q;++i){
        int l,r;
        cin>>l>>r;
        Q[l].push_back({r,i});
    }
    buildtree(0,1,n);
    int ptr = n / k;
    for (int mod = 0; mod < k; ++mod) {
        int last = n - (k + n % k - mod) % k;

        stack<pair<int, int> > S;
        for (int i = last; i >= 1; i -= k) {
            int cur = A[i];
            while (!S.empty() && S.top().first >= cur) {
                int l = pos(S.top().second,mod), r = pos(n,mod), val = S.top().first;
                S.pop();
                if (!S.empty())
                    r = pos(S.top().second - 1,mod);
                update(0, 0, ptr, l, r, -val);
            }
            int l = pos(i,mod), r = pos(n,mod);
            if (!S.empty())
                r = pos(S.top().second - 1,mod);
            update(0, 0, ptr, l, r, cur);
            for (auto[r, qpos]:Q[i]) {
                ans[qpos] = get(0, 0, ptr, pos(i,mod), pos(r,mod));
            }
            update(0, 0, ptr, l, r, -cur);
            cur = get_min(0,1,n,max(1,i-k+1),i);
            while (!S.empty() && S.top().first >= cur) {
                int l = pos(S.top().second,mod), r = pos(n,mod), val = S.top().first;
                S.pop();
                if (!S.empty())
                    r = pos(S.top().second - 1,mod);
                update(0, 0, ptr, l, r, -val);
            }

            l = pos(i,mod), r = pos(n,mod);
            if (!S.empty())
                r = pos(S.top().second - 1,mod);
            update(0, 0, ptr, l, r, cur);
            S.push({cur, i});
        }
        for (int i = 0; i <= ((ptr+1)<<1); ++i)
            T[i] = ::mod[i] = 0;
    }

    for(int i = 1;i<=q;++i)
        cout<<ans[i]<<endl;
}
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}