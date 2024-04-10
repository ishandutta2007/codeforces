// hloya template v19

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
#define files2 freopen("magic.out","w",stdout)
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
const long double eps = 1e-12;
const int maxn = 2e5 + 10, base = 1e9 + 7;
const ll llinf = 1e18 + 5;

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

int main() {
    int n;
    read(n);
    int X, Y;
    read(X, Y);

    pair<ll, char> clothest[8];
    clothest[0].f = -llinf;
    clothest[1].f = llinf;

    clothest[2].f = llinf;
    clothest[3].f = -llinf;

    clothest[4].f = -llinf;
    clothest[5].f = -llinf;

    clothest[6].f = llinf;
    clothest[7].f = llinf;


    for (int i = 0; i < n; i++) {
        char type = endl;
        while (type == endl)
            type = getchar();
        int x, y;
        read(x, y);

        if (x == X) {
            if (y < Y) {
                clothest[3] = max(clothest[3],
                    make_pair((ll)y, type));
            } else {    
                clothest[2] = min(clothest[2],
                    make_pair((ll)y, type));
            }
        }
        if (y == Y) {
            if (x < X) {
                clothest[0] = max(clothest[0],
                    make_pair((ll)x, type));
            } else {
                clothest[1] = min(clothest[1],
                    make_pair((ll)x, type));
            }
        }
        if (x + y == X + Y) {
            if (y < Y) {
                clothest[5] = max(clothest[5],
                    make_pair((ll)y, type));
            } else {    
                clothest[6] = min(clothest[6],
                    make_pair((ll)y, type));
            }
        }
        if (x - y == X - Y) {
            if (y < Y) {
                clothest[4] = max(clothest[4],
                    make_pair((ll)y, type));
            } else {    
                clothest[7] = min(clothest[7],
                    make_pair((ll)y, type));
            }
        }
    }

    bool ans = 0;
    for (int i = 0; i < 8; i++)
        if (clothest[i].f != llinf && clothest[i].f != -llinf) {
            if (i <= 3) {
                if (clothest[i].s != 'B')
                    ans = 1;
            } else {
                if (clothest[i].s != 'R')
                    ans = 1;
            }
        }
    puts(ans ? "YES" : "NO");
    return 0;
}