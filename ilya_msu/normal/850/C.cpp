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
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;



vector<int> genPrimes(int N) {
    vector<int> p(N + 1, 1);
    vector<int> res;
    for (int i = 2; i < p.size(); ++i) {
        if (p[i]) {
            res.push_back(i);
            for (int j = i + i; j < p.size(); j += i)
                p[j] = 0;
        }
    }
    return res;
}

map<int, int> mem;

int get(int n) {
    if (n == 0)
        return 0;
    //cout << n << " " << mem.size() << endl;
    if (mem.find(n) != mem.end())
        return mem[n];
    vector<int> forb;
    for (int i = 1; ; ++i) {
        int a = n >> i;
        int b = n & ((1 << (i - 1)) - 1);
        int x = a | b;
        forb.push_back(get(x));
        if (a == 0)
            break;
    }
    sort(forb.begin(), forb.end());
    if ((forb.empty()) || (forb[0] != 0)) 
        return mem[n] = 0;
    for (int i = 1; i < forb.size(); ++i) {
        if (forb[i] > forb[i - 1] + 1)
            return mem[n] = forb[i - 1] + 1;
    }
    return mem[n] = forb.back() + 1;
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> primes = genPrimes(40000);
    map<int, int> degr;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int j = 0; j < primes.size(); ++j) {
            if ((x % primes[j]) == 0) {
                int c = 0;
                while ((x % primes[j]) == 0) {
                    ++c;
                    x /= primes[j];
                }
                if (degr.find(primes[j]) == degr.end())
                    degr[primes[j]] = 0;
                degr[primes[j]] |= (1 << (c - 1));
            }
        }
        if (x != 1) {
            if (degr.find(x) == degr.end())
                degr[x] |= 1;
        }
    }
    int res = 0;
    for (auto e : degr) {
        res ^= get(e.second);
       
    }
    if (res == 0)
        cout << "Arpa" << endl;
    else
        cout << "Mojtaba" << endl;
}



//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
    
	solve();


#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}