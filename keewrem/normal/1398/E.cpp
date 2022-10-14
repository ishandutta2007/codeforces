#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 200010;
int T;
ll N;
int a, b, qq;
ll fenwick[MAXN], fcnt[MAXN];
void update(int pos, int delta) {
    int qq = 1;
    if (delta < 0)
        qq = -1;
    for (; pos < MAXN; pos += pos & -pos) {
        fenwick[pos] += delta;
        fcnt[pos] += qq;
    }
}
int ycnt = 0;
ll query() {
    int pos = 0, act = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        if (pos + (1LL << i) < MAXN)
            if (act + fcnt[pos + (1LL << i)] <= ycnt) {
                pos += (1LL << i);
                act += fcnt[pos];
                res += fenwick[pos];
            }
    }
    //    cout << "res "<<res <<endl;
    return res;
}
ll sum, cnt, ans;
bool xp[MAXN], yp[MAXN];
map<int, int> lol;
signed main() {
    cin >> N;
    vector<pii> v;
    vi kek;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.pb({a, b});
        if (b > 0)
            kek.pb(b);
    }
    priority_queue<ll> mxx, mny;
    sort(kek.rbegin(), kek.rend());
    for (int i = 0; i < kek.size(); i++)
        lol[kek[i]] = i + 1;
    for (auto x : v) {
        sum += x.se;
        if (x.se > 0)
            cnt++;
        else
            cnt--;
        if (x.fi == 0) {
            if (x.se < 0)
                xp[lol[-x.se]] = 0;
            else {
                xp[lol[x.se]] = 1;
                mxx.push(x.se);
            }
        }
        if (x.fi == 1) {
            if (x.se > 0) {
                ycnt++;
                yp[lol[x.se]] = 1;
                mny.push(-x.se);
            } else {
                ycnt--;
                yp[lol[-x.se]] = 0;
            }
        }
        while ((!mxx.empty()) && xp[lol[mxx.top()]] == 0)
            mxx.pop();
        while ((!mny.empty()) && yp[lol[-mny.top()]] == 0)
            mny.pop();
        update(lol[abs(x.se)], x.se);
        ans = sum;
        ans += query();
        //cout << "sum "<<sum <<" cnt "<<cnt <<" ycnt " <<ycnt <<endl;
        if (ycnt == cnt && cnt > 0)
            ans += mny.top();
        if (cnt > 0 && ycnt > 0 && ycnt < cnt && ((0 - mny.top()) > mxx.top()))
            ans += mny.top() + mxx.top();
        //    if(!mny.empty() && !mxx.empty())cout << "mxx "<<mxx.top()<<" mny "<<mny.top()<<endl;
        //    "<<mny.top()<<endl;
        cout << ans << endl;
    }
    return 0;
}