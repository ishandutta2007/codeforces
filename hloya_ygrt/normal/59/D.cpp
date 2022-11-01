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

int teams[maxn][3];
map<int, int> inTeam, level;

int main() {
    int n;
   // files1;
    read(n);

    for (int i = 0; i < 3 * n; i++) {
        int guy = input<int>() - 1;
        level[guy] = i;    
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) {
            teams[i][j] = input<int>() - 1;
            inTeam[teams[i][j]] = i;
        }

    int k;
    read(k);
    k--;

    vector<int> friends, unused, anyplace, res;

    int myTeam = inTeam[k];
    for (int i = 0; i < 3; i++) {
        if (level[teams[myTeam][i]] < level[k]) {
            for (int i = 0; i < 3 * n; i++)
                if (i != k)
                    printf("%d ", i + 1);
            return 0;
        }
        if (teams[myTeam][i] != k)
            friends.pb(teams[myTeam][i]);
    }

    for (int i = 0; i < myTeam; i++)
        for (int j = 0; j < 3; j++)
            anyplace.pb(teams[i][j]);
    for (int i = myTeam + 1; i < n; i++)
        for (int j = 0; j < 3; j++)
            unused.pb(teams[i][j]);

    sort(all(friends));
    sort(all(unused));
    sort(all(anyplace));

    for (int i:unused)
        friends.pb(i);

    friends.pb(inf);
    anyplace.pb(inf);

    reverse(all(friends)), reverse(all(anyplace));

    while (!(friends.size() == 1 && anyplace.size() == 1)) {
        if (friends.back() < anyplace.back())
            res.pb(friends.back()), friends.pop_back();
        else
            res.pb(anyplace.back()), anyplace.pop_back();
    }

    for (int i:res)
        printf("%d ", i + 1);
    return 0;
}