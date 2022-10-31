// hloya template v21

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

// template<typename T>
// T input(){
//     T ans = 0, m = 1;
//     char c = ' ';

//     while (!((c >= '0' && c <= '9') || c == '-')) {
//         c = getchar();
//     }

//     if (c == '-')
//         m = -1, c = getchar();
//     while (c >= '0' && c <= '9'){
//         ans = ans * 10 + (c - '0'), c = getchar();
//     }
//     return ans * m;
// }

// template<typename T> void read(T& a) { a = input<T>(); }
// template<typename T> void read(T& a, T& b) { read(a), read(b); }
// template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
// template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }

const int inf = 2e9;
const long double eps = 1e-12;
const int maxn = 2650 + 12, base = 1e9 + 7;
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

int cnt[26];
int dp[maxn][maxn]; 

void printAns(string s, int i, int j, bool ins = 0) {
        string res;

    while (i < j) {
        if (s[i] == s[j]) {
            res += s[i];
            i++, j--;
            continue;
        }
        if (dp[i + 1][j] == dp[i][j])
            i++;
        else
            j--;
    }

    string t = res;
    reverse(all(t));
    
    if (i == j && !ins) {
        res += s[i];
    }
    res += t;
    cout << res;
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        cnt[s[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        if (cnt[i] >= 100) {
            for (int j = 0; j < 100; j++)
                cout << char(i + 'a');
            return 0;
        }
    for (int i = 0; i < s.size(); i++)
        dp[i][i] = 1;
    
    pair<int, pii> ans = mp(1, mp(0, 0));

    for (int i = s.size() - 1; i >= 0; i--)
        for (int j = i + 1; j < s.size(); j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            if (s[i] == s[j])
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
            amax(ans, mp(dp[i][j], mp(i, j)));
            if (dp[i][j] == 100) {
                printAns(s, i, j);
                return 0;
            }
            if (dp[i][j] == 101) {
                printAns(s, i, j, 1);
                return 0;
            }
        }
    int i = ans.s.f, j = ans.s.s;
    printAns(s, i, j);
    return 0;
}