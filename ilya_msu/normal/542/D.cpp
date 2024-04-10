#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>
#include<unordered_map>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1000000;
//const int M = 10000000;
map<ll, bool> pp;
vector<int> pre(N, 1);
vector<vector<ll> > divisors;
vector<ll> divs;
map<ll, ll> index;


void init() {
    pre[0] = pre[1] = 0;
    for (ll i = 2; i < N; ++i) {
        if (pre[i]) {
            for (ll j = i + i; j < N; j += i)
                pre[j] = 0;
        
        }
    }
    for (ll i = 2; i < N; ++i) {
        if (pre[i])
            for (ll k = i * i; k < N; k *= i)
                pre[k] = 1;
    }
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool isPrimePower(ll x) {
    if (pp.find(x) != pp.end())
        return pp[x];
    ll xx = x;
    if (x <= 1)
        return 0;
    for (ll d = 2; d * d <= x; ++d) {
        if (x % d == 0) {
            while (x % d == 0)
                x /= d;
            pp[xx] = (x == 1);
            return (x == 1);
        }
    }
    pp[xx] = 1;
    return 1;
}

void init(ll a) {
    divs.clear();
    divisors.clear();
    index.clear();
    for (ll d = 1; d * d <= a; ++d) {
        if (a % d == 0) {
                divs.push_back(d);
            ll x = a / d;
            if (x != d)
                divs.push_back(x);
        }
    }
    sort(divs.begin(), divs.end());
    for (int i = 0; i < divs.size(); ++i) {
        index[divs[i]] = i;
        if (!isPrimePower(divs[i] - 1))
            continue;
        bool ok = false;
        for (int j = 0; j < divisors.size(); ++j) {
            if (gcd(divisors[j][0] - 1, divs[i] - 1) != 1) {
                ok = true;
                divisors[j].push_back(divs[i]);
                break;
            }
        }
        if (!ok)
            divisors.push_back(vector<ll>(1, divs[i]));
    }
}



vector<vector<int> > mem;
int get(ll a, int low) {
    int aa = index[a];
    if (mem[aa][low] != -1)
        return mem[aa][low];
    int res = 0;
    for (int i = low; i < divisors.size(); ++i) {
        if (a < divisors[i][0])
            break;
        for (int j = 0; j < divisors[i].size(); ++j) {
            if (divisors[i][j] == a) {
                ++res;
                continue;
            }
            
            if (a % divisors[i][j])
                continue;
            res += get(a / divisors[i][j], i + 1);
        }
    }
    mem[aa][low] = res;
    return res;
}


ll solve(ll a) {
    if (a == 1)
        return 1;
    init(a);
    mem.assign(divs.size(), vector<int>(divisors.size() + 1, -1));
    //cerr << divs.size() * divisors.size() << endl;
    return get(a, 0);
}

void solve() {
    ll a;
    cin >> a;
    cout << solve(a) << endl;    
}



int bruteSum(int x) {
    int res = 0;
    for (int k = 1; k <= x; ++k) {
        if ((x % k) != 0)
            continue;
        if (gcd(k, x / k) != 1)
            continue;
        res += k;
    }
    return res;
}

int brute(int a) {
    int res = 0;
    for (int x = 1; x <= a; ++x) {
        if (bruteSum(x) == a)
            ++res;
    }
    return res;
}

void test() {
    for (int a = 1; a < 100000; ++a) {
        cerr << a << endl;
        if (solve(a) != brute(a)) {
            cerr << "!!!!!!!!!!!!\n";
            cerr << a << "\t" << solve(a) << "\t" << brute(a) << endl;
            return;
        }
    }
}

//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
    init();
	solve();
    //test();


#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}