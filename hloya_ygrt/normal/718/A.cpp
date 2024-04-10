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
template<typename ... T> void shit(T& ... x){}
template<typename ... T> void dec(T& ... x){shit(--x...);}
template<typename ... T> void inc(T& ... x){shit(++x...);}
#include <unordered_map>
#include <unordered_set>
 
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
const int maxn = 3e5 + 10, base = 1e9 + 7;
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

int main() {
    //files1;
    int n, t;
    fast_io;
    cin >> n >> t;

    string s;
    cin >> s;

    int zpos;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '.')
            zpos = i;
    int inced = 0;

    int can = -1;
    for (int i = zpos + 1; i < s.size(); i++)
        if (s[i] >= '5') {
            can = i;
            break;
        }

    int done = 0;
    while (done < t && can != -1) {
        done++;
        
        int pos = can;
        int oldsz = s.size();

        for (int i = pos; i < oldsz; i++) {
            s.pop_back();
        }

        can = -1;
        if (pos - 1 == zpos) {
            inced++;
        } else {
            s.back()++;
            while (s.back() == '9' + 1) {
                s.pop_back();
                if (s.back() == '.') {
                    inced++;
                } else {
                    s.back()++;
                }
            }
            if (s.back() != '.' && s.back() >= '5')
                can = s.size() - 1;
        }
    }

    if (inced) {
        s[zpos - 1]++;
        for (int i = zpos - 1; i >= 0; i--)
            if (s[i] == '9' + 1) {
                if (i) {
                    s[i] = '0';
                    s[i - 1]++;
                } else {
                    s[i] = '0';
                    s = '1' + s;
                    break;
                }
            } else break;
    }

    if (s.back() == '.')
        s.pop_back();
    cout << s;
    return 0;
}