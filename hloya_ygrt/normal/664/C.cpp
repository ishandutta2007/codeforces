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
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>

using namespace std;

const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 1e6 + 5, base = 1e9+7;

void bad(string mes = "NO"){cout << mes;exit(0);}

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
		m = -1,	c = getchar();
	while (c != ' ' && c != '\n')
		ans = ans * 10 + c - '0', c = getchar();
	return ans * m;
}

template<typename T>
T sqr(T x)
{
	return x * x;
}

char t[maxn];

int main()
{
	int n;
	scanf("%d\n", &n);
	for (int j = 0; j < n; j++){
		int need;
		scanf("IAO'%s\n", t);
		ll cur = 10, pref = 0;
		int sz = strlen(t);
		sscanf(t, "%d", &need);
		
		for (int i = 0; i + 1 < sz; i++){
			pref += cur;
			cur = (cur * 10LL);
		}

		while (need - 1989LL < pref)
			need += cur;
		printf("%d\n", need);
	}
	return 0;
}