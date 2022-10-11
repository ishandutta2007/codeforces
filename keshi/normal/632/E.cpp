//In the name of God
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

typedef int ll;
typedef double ld;
//typedef complex<ld> cd;
typedef pair<ll, ll> pll;

const ll maxn = 3e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ld PI = acos(-1);
const ll LG = 20;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

struct cd{
    double real, img;
 
    inline cd(){
        real = img = 0.0;
    }
 
    inline cd(double x){
        real = x, img = 0.0;
    }
 
    inline cd(double x, double y){
        real = x, img = y;
    }
 
    inline void operator += (cd &other){
        real += other.real, img += other.img;
    }
 
    inline void operator -= (cd &other){
        real -= other.real, img -= other.img;
    }
 
    inline cd operator + (cd &other){
        return cd(real + other.real, img + other.img);
    }
 
    inline cd operator - (cd &other){
        return cd(real - other.real, img - other.img);
    }
 
    inline cd operator * (cd& other){
        return cd((real * other.real) - (img * other.img), (real * other.img) + (img * other.real));
    }
};

inline ll reverse(ll x, ll lg){
	ll y = 0;
	for(ll i = 0; i < lg; i++){
		if((x >> i) & 1) y += (1ll << (lg - i - 1));
	}
	return y;
}

ll rev[maxn];

inline void fft(cd* a, bool inv = 0){
	ll lg = LG;
	ll n = (1ll << lg);
	for(ll i = 0; i < n; i++){
		ll j = rev[i];
		if(i < j) swap(a[i], a[j]);
	}
	for(ll len = 2; len <= n; len *= 2){
		ld ang = 2 * PI / len * (inv ? -1 : 1);
		cd wlen(cos(ang), sin(ang));
		for(ll i = 0; i < n; i += len){
			cd w(1);
			for(ll j = 0; j < len / 2; j++){
				cd v = a[i + j], u = w * a[i + j + len / 2];
				a[i + j] = v + u;
				a[i + j + len / 2] = v - u;
				w = w * wlen;
			}
		}
	}
	if(inv){
		for(ll i = 0; i < n; i++){
			a[i].real /= n;
		}
	}
	return;
}
inline void multiply(cd* a, cd* b){
	fft(a);
	for(ll i = 0; i < (1 << LG); i++){
		a[i] = a[i] * b[i];
	}
	fft(a, -1);
	for(ll i = 0; i < (1 << LG); i++){
		if(a[i].real > 0.1) a[i] = 1;
		else a[i] = 0;
	}
}
inline void multiply2(cd* a){
	fft(a);
	for(ll i = 0; i < (1 << LG); i++){
		a[i] = a[i] * a[i];
	}
	fft(a, -1);
	for(ll i = 0; i < (1 << LG); i++){
		if(a[i].real > 0.1) a[i] = 1;
		else a[i] = 0;
	}
}

ll n, k;
cd a[maxn], b[maxn];

void solve(ll x){
	if(x == 0) return;
	if(x & 1){
		solve(x - 1);
		multiply(b, a);
	}
	else{
		solve(x >> 1);
		multiply2(b);
	}
}

int main(){
    fast_io;
    for(ll i = 0; i < (1 << LG); i++){
    	rev[i] = reverse(i, LG);
	}
    cin >> n >> k;
    for(ll i = 0; i < n; i++){
    	ll x;
    	cin >> x;
    	a[x] = cd(1);
	}
	fft(a);
	b[0] = cd(1);
	solve(k);
	for(ll i = 0; i < (1 << LG); i++){
		if(b[i].real > 0.1){
			cout << i << " ";
		}
	}
	cout << "\n";
 
    return 0;
}