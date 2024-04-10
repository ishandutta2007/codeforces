#include <bits/stdc++.h>
using namespace std;
 

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
 
#define ll long long
#define ld long double
#define pii pair<int,int>
 
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
 
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
// template<typename ... T> void shit(T& ... x){}
// template<typename ... T> void dec(T& ... x){shit(--x...);}
// template<typename ... T> void inc(T& ... x){shit(++x...);}
 
template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}
 
template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
 
    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }
 
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}
 
template<typename T>
void read(T& a) {
    a = input<T>();
}
 
template<typename T>
void read(T& a, T& b) {
    read(a), read(b);
}
 
template<typename T>
void read(T& a, T& b, T& c) {
    read(a, b), read(c);
}
 
template<typename T>
void read(T& a, T& b, T& c, T& d) {
    read(a, b), read(c, d);
}
 
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 1e5 + 10, base = 1e9 + 7;
const ll llinf = 1e18 + 1;
 
template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

int ar[maxn];
int cnt[maxn];
int n, m;
int b[maxn];

int find_pos(int mda) {
    for (int i = 0; i < n; i++) {
        if (b[i] == mda)
            return i;
    }
    return -1;
}

void pr(int ans) {
    int ans1 = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] != b[i])
            ans1++;
    }
    cout << ans << ' ' << ans1 << endl;
    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    exit(0);
}

bool can(int mincnt, bool print) {
    multiset<int> useless;
    set<pair<int, int> > worst;

    for (int i = 0; i < n; i++)
        b[i] = ar[i];

    for (int i = 1; i <= m; i++)
        cnt[i] = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] <= m)
            cnt[b[i]]++;
        else
            useless.insert(b[i]);
    }

    for (int i = 1; i <= m; i++) {
        worst.insert(mp(cnt[i], i));
    }

    while (1) {
        int kek = (*worst.begin()).second;
        if (cnt[kek] >= mincnt) {
            if (print)
                pr(mincnt);
            return 1;
        }

        worst.erase(worst.begin());

        if (!useless.empty()) {
            int mda = (*useless.begin());
            useless.erase(useless.begin());

            int pos = find_pos(mda);
            b[pos] = kek;
            cnt[kek]++;

            worst.insert(mp(cnt[kek], kek));
        } else {
            int mda = (*(--worst.end())).second;
            worst.erase(--worst.end());

            if (cnt[mda] > mincnt) {
                int pos = find_pos(mda);
                b[pos] = kek;
                cnt[kek]++;
                cnt[mda]--;

                worst.insert(mp(cnt[kek], kek));
                worst.insert(mp(cnt[mda], mda));
            } else
                return 0;
        }
    }
            if (print)
                pr(mincnt);
    return 1;
}

int main() {
    read(n, m);

    for (int i = 0; i < n; i++) {
        read(ar[i]);
    }

    if (m == 1) {
        int ans = n, ans1 = 0;
        for (int i = 0; i < n; i++) {
            if (ar[i] != 1)
                ans1++;
            ar[i] = 1;
        }
        cout << ans << ' ' << ans1 << endl;
        for (int i = 0; i < n; i++)
            cout << ar[i] << ' ';
        exit(0);
    }
    // can(1, 0);
    int l = 0, r = n;
    while (r - l > 1) {
        int c = (l + r) >> 1;
        if (can(c, 0))
            l = c;
        else
            r = c;
    }

    if (can(r, 0))
        can(r, 1);
    else
        if (can(l, 0))
            can(l, 1);
    return 0;
}