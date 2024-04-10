#include <bits/stdc++.h>
#include <valarray>
using namespace std;

bool dbg = 0;

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

template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }

void reads(string & s) {
    string ans = "";
    char c = endl;
    while (c == endl || c == ' ')
        c = getchar();
    while (c != endl && c != ' ' && c)
        ans += c, c = getchar();
    s = ans;
}

const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 2e5 + 10, base = 1e9 + 7;
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

void go_left_and_up(int& x, int& y) {
    if (y == 1) {
        if (x == 0) {
            y = 0;
            return;
        }
        x--;
    } else {
        x++;
    }
}

int cnt[30];

int main() {
    string s;
    //files1;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
        cnt[s[i] - 'A']++;

    char badC;
    for (int i = 0; i < 26; i++)
        if (cnt[i] == 2)
            badC = i + 'A';

    int f = -1, r;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == badC) {
            if (f == -1)
                f = i;
            else
                r = i;
        }
    int len = r - f - 1;
    if (len == 0)
        bad();

    char ans[20][5];
    // cout << len << endl;

    if (len % 2 == 0) {
        int pos;
        for (int i = 0; i < 13; i++)
            if ((12 - i) * 2 == len)
                pos = i;
        ans[pos][1] = badC;

        string mid = s.substr(f + 1, len);
        for (int i = pos + 1; i < 13; i++) {
            ans[i][0] = mid.back();
            ans[i][1] = mid.front();
            mid.erase(mid.begin());
            mid.pop_back();
        }
        string before = s.substr(0, f);
        int i = pos, j = 1;
        go_left_and_up(i, j);
        while (!before.empty()) {
            ans[i][j] = before.back();
            before.pop_back();
            go_left_and_up(i, j);
        }

        string after = s.substr(r + 1, 26 - r);
        while (!after.empty()) {
            ans[i][j] = after.back();
            after.pop_back();
            go_left_and_up(i, j);
        }
    } else {
        int pos;
        for (int i = 0; i < 13; i++)
            if ((12 - i) * 2 + 1 == len)
                pos = i;
        ans[pos][1] = badC;

        string mid = s.substr(f + 1, len);
        for (int i = pos + 1; i < 13; i++) {
            ans[i - 1][0] = mid.back();
            ans[i][1] = mid.front();
            mid.erase(mid.begin());
            mid.pop_back();
        }
        assert(mid.size() == 1);
        ans[12][0] = mid[0];

        string before = s.substr(0, f);
        int i = pos, j = 1;
        go_left_and_up(i, j);
        while (!before.empty()) {
            ans[i][j] = before.back();
            before.pop_back();
            go_left_and_up(i, j);
        }

        string after = s.substr(r + 1, 26 - r);
        while (!after.empty()) {
            ans[i][j] = after.back();
            after.pop_back();
            go_left_and_up(i, j);
        }
    }

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 13; i++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}