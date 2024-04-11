#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
ll N;
ll num[5001];
ll numsum[5001];
ll divisor[5001][5001];
ll sum[5001][5001];

ll f(ll lb, ll ub, ll factor) {
    if(lb == ub) return 0;
    if(factor == 1) return 0;
    ll Contain = numsum[ub-1] - numsum[lb-1];
    if(Contain == 0) return 0;
    //cerr << "call: " << lb << " " << ub << " " << factor << endl;
    ll LazySum = 0;
    for(int i = lb; i < ub; i++) {
        LazySum += sum[i][factor-1] * num[i];
        //cerr << "lazy: " << i << " " << sum[i][factor-1] << " " << num[i] << endl;
    }
    ll factorsum = 0;
    for(int i = lb; i < ub; i++) {
        factorsum += divisor[i][factor] * num[i];
    }
    //cerr << LazySum << " " << factorsum << " " << Contain << endl;
    ll ret = LazySum + factorsum;
    vector<ll> v;
    v.push_back(lb);
    for(int i = lb + 1; i < ub; i++) {
        if(divisor[i][factor] != divisor[i-1][factor]) v.push_back(i);
    }
    v.push_back(ub);
    factorsum -= Contain * divisor[v[0]][factor];
    ll already = 0;
    for(int i = 0; i + 1 < v.size(); i++) {
        ll nowfactor = divisor[v[i]][factor];
        ll now = (N - Contain) * nowfactor;
        ll nownum = numsum[v[i+1]-1] - numsum[v[i]-1];
        ll nowLazySum = LazySum;
        for(int j = v[i]; j < v[i+1]; j++) {
            nowLazySum -= sum[j][factor-1] * num[j];
        }
        now += nowLazySum;
        now += factorsum;
        //cerr << "query: " << lb << " " << ub << " " << factor << " " << nowfactor << " " << factorsum << " " << nowLazySum << " " << now << endl;
        already += nownum;
        if(i + 2 != v.size()) factorsum += (2 * already - Contain) * (divisor[v[i+1]][factor] - divisor[v[i]][factor]);
        //nowfactor -= (Contain - already);
        now += f(v[i], v[i+1], factor - 1);
        chmin(ret, now);
    }
    //cerr << "result: " << lb << " " << ub << " " << factor << " " << ret << endl;
    return ret;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        ll x;
        cin >> x;
        if(x == 0) x++;
        num[x]++;
    }
    for(int i = 1; i <= 5000; i++) {
        numsum[i] = numsum[i-1] + num[i];
    }
    for(ll val = 1; val <= 5000; val++) {
        for(int i = 0; i <= 5000; i++) {
            divisor[val][i] = divisor[val-1][i];
        }
        ll copy = val;
        for(ll i = 2; i * i <= copy; i++) {
            while(copy % i == 0) {
                divisor[val][i]++;
                copy /= i;
            }
        }
        if(copy != 1) divisor[val][copy]++;
        for(int i = 1; i <= 5000; i++) {
            sum[val][i] = sum[val][i-1] + divisor[val][i];
        }
    }
    cout << f(1, 5001, 5000) << endl;
    return 0;
}