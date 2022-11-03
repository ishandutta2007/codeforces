#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using comp = complex<double>;

const ld pi = acosl(-1.);
const ll REAL_MAXDEG = 20LL;
const ll REAL_MAXN = (1LL << REAL_MAXDEG);
comp w[REAL_MAXN + 1];
ll bitwise[REAL_MAXN];

void fft(vector<comp>& v, ll deg, bool inverse){
    const ll N = 1LL << deg;
    ll cur = 0;
    for(ll i = 1; i < N; ++i){
        cur = bitwise[i << (REAL_MAXDEG - deg)];
        if(cur > i){
            swap(v[i], v[cur]);
        }
    }
    vector<comp> ww(N);

    for(ll step = 2, half = 1, mult = REAL_MAXDEG - 1; step <= N; step <<= 1LL, half <<= 1LL, --mult){
        if(inverse){
            for(ll i = 0; i < half; ++i){
                ww[i] = w[REAL_MAXN - (i << mult)];
            }
        }else{
            for(ll i = 0; i < half; ++i){
                ww[i] = w[(i << mult)];
            }
               
        }

        for(ll beg = 0; beg < N; beg += step){
            for(ll i = 0; i < half; ++i){
                comp x = v[beg + i];
                comp y = v[beg + i + half];
                y = y * ww[i];
                v[beg + i] = x + y;
                v[beg + i + half] = x - y;
            }
        }
    }
    if(inverse){
        for(ll i = 0; i < N; ++i){
            v[i] /= N;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    ll m;
    string s;
    cin >> n;
    for(ll i = 0; i < REAL_MAXN + 1; ++i){
        w[i] = {cosl(2 * pi * i / REAL_MAXN), sinl(2 * pi * i / REAL_MAXN)};
    }
    bitwise[0] = 0;
    ll cur = 0;
    for(ll i = 1; i < REAL_MAXN; ++i){
        for(ll j = (1LL << (REAL_MAXDEG - 1)); j >= 1; j >>= 1LL){
            cur ^= j;
            if(cur & j){
                break;
            }
        }
        bitwise[i] = cur;
    }
    for(ll ttt = 0; ttt < n; ++ttt){
        vector<ll> answer;
        cin >> m;
        cin >> s;
        if(m == 1){
            cout << "1\n1" << endl;
            continue;
        }
        ll log = 0;
        ll cur = m;
        while(cur > 0){
            cur >>= 1LL;
            ++log;
        }
        log = max(log, 4LL);
        ll MAXN = 1LL << (log + 1);
        vector<comp> a(MAXN);
        for(ll i = 0; i < m; ++i){
            a[i] = {(s[i] == 'V' ? 1 : 0), (s[m - 1 - i] == 'K' ? 1 : 0)};
        }
        fft(a, log + 1, false);
        for(ll i = 0; i < MAXN; ++i){
            a[i] *= a[i];
        }
        fft(a, log + 1, true);
        vector<ll> ans(m + 1, 0);
        for(ll i = 0; i <= m - 1; ++i){
            if(floor(a[m - 1 + i].imag() * 0.5 + 0.5) >= 1 || floor(a[m - 1 - i].imag() * 0.5 + 0.5) >= 1){
                ans[i] = 1;
            }
        }
        for(ll i = 1; i <= m; ++i){
            if(ans[i] == 0){
                for(ll j = i << 1LL; j <= m; j += i){
                    if(ans[j]){
                        ans[i] = 1;
                        break;
                    }
                }
                if(ans[i] == 0){
                    answer.push_back(i);
                }
            }
        }
        cout << answer.size() << endl;
        for(ll i = 0; i < answer.size(); ++i){
            if(i){
                cout << " ";
            }
            cout << answer[i];
        }
        cout << endl;
    }
}