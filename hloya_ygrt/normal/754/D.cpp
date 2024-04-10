// hloya template v22

// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

#include <bits/stdc++.h>
#include <valarray>
using namespace std;

bool dbg = 0;

clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC

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
void bad(int mes = -1){cout << mes;exit(0);}

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
void amax(T& x, T y) {
    x = max(x, y);
}

template<typename T>
void amin(T& x, T y) {
    x = min(x, y);
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

template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }

const int inf = 2e9;
const long double eps = 1e-12;
const int maxn = 3e5 + 12, base = 1e9 + 7;
const ll llinf = 4e18 + 5;

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

int l[maxn], r[maxn];

int main() {
    int n, k;
    
    read(n, k);

    vector<pii> event;
    for (int i = 0; i < n; i++) {
        read(l[i], r[i]);
        event.pb(mp(l[i], r[i]));
    }
    if (k == 1) {
        int ansLen = -1, ans;
        for (int i = 0; i < n; i++)
            if (r[i] - l[i] + 1 > ansLen)
                ansLen = r[i] - l[i] + 1, ans = i;
        cout << ansLen << endl;
        cout << ans + 1 << endl;
        return 0;
    }

    sort(all(event));

    set<pair<int, int> > setik;
    int cur = 0;
    for (int i = 0; i < k - 1; i++)
        setik.insert(mp(-inf/2 - 3, cur++));
    auto it = setik.begin();

    pair<int, pii> ans;
    ans = mp(0, mp(inf, -inf));

    for (int i = 0; i < n; i++) {
        int curL = event[i].f;
        int curR = event[i].s;

        int rFromSetic = it->f;
        int R = min(rFromSetic, curR);
        
        // cout << R << ' ';
        // cout << curL << endl;

        ans = max(ans, mp(R - curL + 1, mp(curL, R)));

        setik.insert(mp(curR, cur++));
        if (curR >= rFromSetic) {
            it++;
        }
    }

    assert(ans.f != -1);

    printf("%d\n", ans.f);
    int L = ans.s.f, R = ans.s.s;
    int cnt = 0;

    for (int i = 0; i < n && cnt < k; i++) {
        if (l[i] <= L && r[i] >= R) {
            printf("%d ", i + 1);
            cnt++;
        }
    }
    return 0;
}