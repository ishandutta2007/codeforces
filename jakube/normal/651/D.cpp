#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);
const long long int MOD = 1e9 + 7;

typedef long long int lint;
typedef long double ld;
lint powmod(lint a,lint b, lint mod) {lint res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int debug = 1;
template <typename T, typename S>
void DBG(pair<T, S> p){if(debug)cout<<p.first<<" "<<p.second<<endl;}
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    lint n, a, b, T;
    cin >> n >> a >> b >> T;
    string st, s;
    cin >> st;

    int m = 0;

    FOR(k, 2) {
        s = st;
        if (k)
        {
            FORR(i, 1, n)
            {
                int j = n - i;
                if (i > j)
                {
                    char tmp = s[i];
                    s[i] = s[j];
                    s[j] = tmp;
                }
            }
        }



        vector<int> psum(n), rsum(n + 1);
        psum[0] = 1 + (s[0] == 'w' ? b : 0);
        FORR(i, 1, n) {
            psum[i] = psum[i - 1] + 1 + (s[i] == 'w' ? b : 0);
        }
        rsum[n] = 0;
        rsum[n - 1] = 1 + (s[n - 1] == 'w' ? b : 0);
        for (int i = n - 2; i >= 0; i--) {
            rsum[i] = rsum[i + 1] + 1 + (s[i] == 'w' ? b : 0);
        }

        FOR(i, n) {
            lint Time_remaining = T - psum[i] - a * i;
            if (Time_remaining < 0)
                break;

            int seen = i + 1;
            if (seen > m)
                m = seen;

            Time_remaining -= a * i;
            if (Time_remaining < 0)
                continue;

            int left = i + 1;
            int right = n;
            while (left + 1 < right) {
                int middle = (left + right) / 2;
                //DBG(vector<int>{left, middle, right});
                int time = Time_remaining - rsum[middle] - (n - middle) * a;
                int seen2 = seen + (n - middle);
                if (time >= 0 && seen2 > m) {
                    m = seen2;
                }

                if (time < 0)
                    left = middle;
                else
                    (right = middle);
            }

            int time = Time_remaining - rsum[left] - (n - left) * a;
            int seen2 = seen + (n - left);
            if (time >= 0 && seen2 > m)
                m = seen2;

            time = Time_remaining - rsum[right] - (n - right) * a;
            seen2 = seen + (n - right);
            if (time >= 0 && seen2 > m)
                m = seen2;
        }
    }

    cout << m;
}