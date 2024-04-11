#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define fin(name) freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const int mod = (int)1e9 + 7;
const dbl eps = (dbl)1e-8;
const int maxn = (int)1e5 + 5;
const dbl pi = acos(-1);

string s, t;
int as[maxn], bs[maxn], at[maxn], bt[maxn];

int main() {
//    fin("t.in");
    sync;
    cin >> s;
    cin >> t;
    clean(as); clean(bs); clean(at); clean(bt); 
    F(i, 0, sz(s)) {
    	as[i] += (s[i] == 'A');
    	if (s[i] != 'A')
    		as[i] = 0;
    	bs[i] += (s[i] == 'B' || s[i] == 'C');
    	as[i + 1] = as[i];
    	bs[i + 1] = bs[i];
    }
    F(i, 0, sz(t)) {
    	at[i] += (t[i] == 'A');
    	if (t[i] != 'A')
    		at[i] = 0;
    	bt[i] += (t[i] == 'B' || t[i] == 'C');
    	at[i + 1] = at[i];
    	bt[i + 1] = bt[i];
    }

    string ans = "";
    int m;
    cin >> m;
    F(i, 0, m) {
    	int ls, rs, lt, rt;
    	cin >> ls >> rs >> lt >> rt; --ls; --rs; --lt; --rt;
    	int kas = min(as[rs], rs - ls + 1);
    	rs -= kas;
    	int kat = min(at[rt], rt - lt + 1);
    	rt -= kat;
    	int ss = (rs < 0 ? 0 : bs[rs]) - (ls == 0 ? 0 : bs[ls - 1]);
    	int st = (rt < 0 ? 0 : bt[rt]) - (lt == 0 ? 0 : bt[lt - 1]);
//    	cout << i << " " << ss << " " << st << " " << kas << " " << kat << " " << endl;
    	int ost = (kas - kat) % 3;
    	if (ss == 0) {
    		if (st == 0) {
    			if (kas >= kat && ost == 0)
    				ans += '1';
    			else
    				ans += '0';
    			cont;
    		}
    		ss += 2;
    		kas -= 1;
    		kas -= abs(kas - kat) % 3;
    		ost = (kas - kat) % 3;
    	}
    	if (ss <= st && ss % 2 == st % 2 && kas >= kat && (ost == 0 || (st - ss) >= 2))
    		ans += '1';
    	else
    		ans += '0';
    }
    cout << ans << endl;
    return 0;
}