#include <bits/stdc++.h>
#include <valarray>
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

int l[26], m[26], w[26];
int pw[26];

// vector<short> prs;

template<typename T>
void amax(T& x, T y) {
    x = max(x, y);
}

void mda(int x) {
    if (x != 0)
        cout << "L";
    if (x != 1)
        cout << "M";
    if (x != 2)
        cout << "W";
    puts("");
}

int main() {
//    files1;
    map<pair<int, int>, pair<int, int> > smallpart;
    
    int n;
    read(n);

    pw[0] = 1;
    for (int i = 1; i < 26; i++)
        pw[i] = pw[i - 1] * 3;

    for (int i = 0; i < n; i++) {
        read(l[i], m[i], w[i]);
    }

    if (n == 1) {
        if (l[0] == m[0])
            bad("LM");
        if (l[0] == w[0])
            bad("LW");
        if (m[0] == w[0])
            bad("MW");
        bad();
    }

    int lp = n / 2;
    int rp = n - lp;

    for (int mask = 0; mask < pw[lp]; mask++) {
        int copy = mask;
        int sum[3] = {0};

        for (int i = 0; i < lp; i++, copy /= 3) {
            int cur = copy%3;
            if (cur != 0)
                sum[0] += l[i];
            if (cur != 1)
                sum[1] += m[i];
            if (cur != 2)
                sum[2] += w[i];
        }

        if (!smallpart.count(mp(sum[1] - sum[0], sum[2] - sum[0])))
            smallpart[mp(sum[1] - sum[0], sum[2] - sum[0])] = mp(-inf, -inf);
        amax(smallpart[mp(sum[1] - sum[0], sum[2] - sum[0])], mp(sum[0], mask));
    }

    pair<int, pii> ans;
    ans.f = -inf;

    for (int mask = 0; mask < pw[rp]; mask++) {
        int copy = mask;
        int sum[3] = {0};

        for (int i = lp; i < n; i++, copy /= 3) {
            int cur = copy%3;
            if (cur != 0)
                sum[0] += l[i];
            if (cur != 1)
                sum[1] += m[i];
            if (cur != 2)
                sum[2] += w[i];
        }

        int d1 = sum[0] - sum[1], d2 = sum[0] - sum[2];
        if (!smallpart.count(mp(d1, d2)))
            continue;
        pair<int, int> f_mask = smallpart[mp(d1, d2)];

        // if (mask == 64) {
        //     // cout << sum[0] << ' ' << sum[1] << ' ' << sum[2] << endl;
        //     // cout << 
        //     exit(0);
        // }

        ans = max(ans, mp(f_mask.f + sum[0], mp(f_mask.s, mask)));
    }

    if (ans.f == -inf)
        bad();

    // int resSum
    for (int i = 0; i < lp; i++) {
        mda(ans.s.f % 3);
        ans.s.f /= 3;
    }
    for (int i = 0; i < rp; i++) {
        mda(ans.s.s % 3);
        ans.s.s /= 3;
    }
    return 0;
}