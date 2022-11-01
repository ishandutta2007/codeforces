// hloya template v24

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
#define umap unordered_map<int, int>

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out1.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}

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

const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = 2e5 + 12, base = 1e9 + 7;
const ll llinf = 2e18 + 5;

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

string a[100];
int ans[100];
bool used[100];

int main() {
    //files1;
//    ifstream cin( "input.txt" );
    int n, k;
    cin >> n >> k;
    int haveYes = -1;
    for ( int j = 0; j <= n - k; j++ ) {
        cin >> a[j];
        if ( a[j] == "YES" )
            haveYes = j;
    }
    if ( haveYes == -1 ) {
        for ( int j = 0; j < n; j++ )
            cout << "Aa" << ' ';
        return 0;
    }
    for ( int j = haveYes; j < haveYes + k; j++ )
        ans[j] = j - haveYes;
    // cout << haveYes << endl;
    for ( int j = haveYes + 1; j <= n - k; j++ )
        if ( a[j] == "NO" ) {
            // cout << 1;
            for ( int i = 0; i < 100; i++ )
                used[i] = false;
            bool haveDiff = false;
            for ( int i = j; i < j + k - 1; i++ ) {
                if ( used[ans[i]] )
                    haveDiff = true;
                used[ans[i]] = true;
                // cout << ans[i] << endl;
            }
            if ( haveDiff ) {
                for ( int i = 0; i < 100; i++ )
                    if ( !used[i] ) {
                        ans[j + k - 1] = i;
                        break;
                    }
                continue;
            }
            ans[j + k - 1] = ans[j];
        } else {
            for ( int i = 0; i < 100; i++ )
                used[i] = false;
            for ( int i = j; i < j + k - 1; i++ ) {
                used[ans[i]] = true;
            }
            for ( int i = 0; i < 100; i++ )
                if ( !used[i] ) {
                    ans[j + k - 1] = i;
                    break;
                }
        }
    for ( int j = haveYes - 1; j >= 0; j-- )
       if ( a[j] == "NO" ) {
            for ( int i = 0; i < 100; i++ )
                used[i] = false;
            bool haveDiff = false;
            for ( int i = j + 1; i < j + k; i++ ) {
                if ( used[ans[i]] )
                    haveDiff = true;
                used[ans[i]] = true;
            }
            if ( haveDiff ) {
                for ( int i = 0; i < 100; i++ )
                    if ( !used[i] ) {
                        ans[j] = i;
                        break;
                    }
                continue;
            }
            ans[j] = ans[j + k - 1];
        } else {
            for ( int i = 0; i < 100; i++ )
                used[i] = false;
            for ( int i = j + 1; i < j + k; i++ ) {
                used[ans[i]] = true;
            }
            for ( int i = 0; i < 100; i++ )
                if ( !used[i] ) {
                    ans[j] = i;
                    break;
                }
        }
    for ( int j = 0; j < n; j++ ) {
        cout << 'A';
        if ( ans[j] < 26 )
            cout << (char) ('a' + ans[j]) << ' ';
        else
            cout << (char)('a' + ans[j] - 26) << (char)('a' + ans[j] - 26) << ' ';
    }
}