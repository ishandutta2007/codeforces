// Hydro submission #62c5664bc3a9fda562296e26@1657103947832
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define is_set(x, i) (((x)>>(i))&1)
#define set_bit(x, i) {(x) |= 1ll<<(i);}
#define unset_bit(x, i) {(x) = ((x) | (1ll<<(i))) ^ (1ll<<(i));}


#ifdef JUNCO_DEBUG
#define echoarr(x) {for(int _i=0,_n=min((size_t)15,sizeof(x)/sizeof(x[0]));_i<_n;_i++)\
 {cout << x[_i] << " ";} cout << endl;}
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );cout<<endl;}
#define echo2(x) {cout<<#x<<endl; for(auto el : x) {ECHO(el); cout << endl;}}
#else
#define echoarr(x)
#define echo(...) 
#define echo2(x) 
#endif

const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = 0x3f3f3f3f3f3f3f3f;

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){if(_s)cout<<"true";else cout<<"false";}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}//for s.size()
void ECHO(long long unsigned _s) {cout<<_s;}
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){if(_s == inf)cout << "inf";else cout<<_s;}
void ECHO(double _s){cout.precision(7);cout<<fixed<<_s;}
void ECHO(long double _s){cout.precision(7);cout<<fixed<<_s;}
void ECHO(bitset<8> b) {cout << b;}//resize bitset
template<typename T> void ECHO(set<T> _s) {
    for(auto el : _s) {ECHO(el); cout << "_";}
}
template<typename T1, typename T2> void ECHO(map<T1, T2> _s) {
    for(auto el : _s) {ECHO(el); cout << "_";}
}
template<typename T1, typename T2> void ECHO(pair<T1, T2> _s) {
    cout << "("; ECHO(_s.fi); cout << ","; ECHO(_s.se); cout << ")";
}
template<typename T> void ECHO(vector<T> v) {
    for(auto el : v) {ECHO(el); cout << "_";}
}
template<typename T> void ECHO(priority_queue<T> pq) {
    priority_queue<T> _pq = pq;
    while(!_pq.empty()) {ECHO(_pq.top()); cout << "->"; _pq.pop();}
}
template<typename T, typename ...Args> void ECHO(string _s, T x, Args... args){
    int _i, c = 0;
    for(_i = 0; _i < (int)_s.size(); _i++) {
        if(c==0 && _s[_i]==',') break;
        if(_s[_i] == '(') c++;
        if(_s[_i] == ')') c--;
    }
    cout << " (" << _s.substr(0, _i) << "): "; ECHO(x);
    while(_i < (int)_s.size() && (_s[_i] == ',' || _s[_i] == ' ')) _i++;
    ECHO(_s.substr(_i), args...);
}

template<typename T> // Input vector<T>.
istream& operator >> (istream& is, vector<T>& v) {
    for(T& el : v) is >> el;
    return is;
}

template<typename T> // Output vector<T>.
ostream& operator << (ostream& os, const vector<T>& v) {
    bool _first = false;
    for(T el : v) {
        if(_first) os << " ";
        _first = true;
        os << el;
    }
    return os;
}

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;




int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, k, i, j, num, mx1, mn1, mx2, mn2;
    int px, py;
    bool ok;

    cin >> n >> k;
    vi posx(n*n+1, 0), posy(n*n+1, 0);
    vector<vi> dp(n, vi(n, 0));
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cin >> num;
            posx[num] = i;
            posy[num] = j;
        }
    }
    px = posx[n*n];
    py = posy[n*n];
    dp[px][py] = 1;
    mx1 = px + py;
    mn1 = px + py;
    mx2 = px - py;
    mn2 = px - py;
    for(i = n*n-1; i > 0; i--) {
        ok = true;
        px = posx[i];
        py = posy[i];
        if(abs(px + py - mx1) > k) ok = false;
        if(abs(px + py - mn1) > k) ok = false;
        if(abs(px - py - mx2) > k) ok = false;
        if(abs(px - py - mn2) > k) ok = false;
        if(ok) {
            dp[px][py] = 1;
            mx1 = max(mx1, px + py);
            mn1 = min(mn1, px + py);
            mx2 = max(mx2, px - py);
            mn2 = min(mn2, px - py);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(dp[i][j]) cout << "M";
            else cout << "G";
        }
        cout << endl;
    }


    return 0;
}