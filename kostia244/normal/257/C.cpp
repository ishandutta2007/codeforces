#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 6969701591;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
using vec = complex<ld>;
ll dot(vec a, vec b) {
	return (conj(a)*b).real();
}
ll cross(vec a, vec b) {
	return (conj(a)*b).imag();
}
#define M_PI 3.14159265358979323846
int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    vector<ld> a, b;
    cin >> n;
    if(n == 1) {
    	return cout << 0, 0;
    }
    for(int x, y, i = 0; i < n; i++) {
    	cin >> x >> y;
    	vec t = vec(x, y);
    	t/=abs(t);
    	ld ans = acos(t.real())*(180./M_PI);
    	if(t.imag() < 0)
    		ans = 360.-ans;
    	a.pb(ans);
    }
    sort(all(a));
    b.pb(a[0]);
    for(int i = 1; i < a.size(); i++) if(fabs(a[i]-a[i-1])>1e-6)b.pb(a[i]);
    ld ans = 1e3;
    a=b;
    a.pb(a[0]);
    for(int i = 1; i < a.size(); i++) ans = min(ans,fmodl(360. -fmodl(360.+a[i]-a[i-1], 360.), 360.));
    if(fabs(360.-ans)<1e-6)ans-=360;
    cout <<fixed<<setprecision(15)<< ans;
}