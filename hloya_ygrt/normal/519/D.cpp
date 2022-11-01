#include <bits/stdc++.h>
#include <windows.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define forn() for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'

using namespace std;

const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 2e5 + 500, base = 1073676287;
const int sigm = 26;

void bad(string mes = "Impossible"){cout << mes;exit(0);}

template<typename T>
string bin(T x){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % 2);
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}

template<typename T = int >
T input(){
    T ans = 0, m = 1;
    char c = ' ';
    while (c == ' ' || c == '\n')
        c = getchar();
    if (c == '-')
        m = -1, c = getchar();
    while (c != ' ' && c != '\n')
        ans = ans * 10 + c - '0', c = getchar();
    return ans * m;
}

template<typename T = int >
T binpow(T n, T s)
{
    if (s == 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2) % base;
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

template<typename T>
T sqr(T x)
{
    return x * x;
}

int cost[sigm];
map<ll, int> cnt[sigm];

int main()
{
    // files1;
	fast_io;
//	cost[0] = 1;
	for (int i = 0; i < sigm; i++)
		cin >> cost[i];
	string s;
	cin >> s;

	ll ans = 0, pref = 0;

	for (int i = 0; i < s.size(); i++){
		ans += cnt[s[i] - 'a'][pref];
		pref += cost[s[i] - 'a'];
		cnt[s[i] - 'a'][pref]++;
	}

	cout << ans << "\n";
	return 0;
}