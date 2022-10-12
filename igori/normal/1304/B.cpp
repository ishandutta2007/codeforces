#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

using std::setprecision;
using std::fixed;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

ll min(ll a, ll b) {return a < b ? a : b;}
ll min(int a, ll b) {return a < b ? a : b;}
ll min(ll a, int b) {return a < b ? a : b;}
ll min(int a, int b) {return a < b ? a : b;}

ll max(ll a, ll b) {return a > b ? a : b;}
ll max(int a, ll b) {return a > b ? a : b;}
ll max(ll a, int b) {return a > b ? a : b;}
ll max(int a, int b) {return a > b ? a : b;}

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
#define y1 y1337
int n, m;
string s[500];
vector<string> ans1, ans2;
int us[500];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
    	cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
    	string t = s[i];
    	reverse(all(t));
    	for (int j = i + 1; j < n; j++)
    	{
    		if (t == s[j] && !us[j])
    		{
    			ans1.push_back(s[i]);
    			ans2.push_back(s[j]);
    			us[j] = 1, us[i] = 1;
    			break;
    		}
    	}
    }
    for (int i = 0; i < n; i++)
    {
    	string t = s[i];
    	reverse(all(t));
    	for (int j = i; j == i; j++)
    	{
    		if (t == s[j] && !us[j])
    		{
    			cout << ans1.size() * m + ans2.size() * m + s[j].size() << endl;
    			for (auto e : ans1) cout << e;
    			cout << s[j];
    			reverse(all(ans2));
    			for (auto e : ans2) cout << e;
    			return 0;
    		}
    	}
    }
    reverse(all(ans2));
    cout << ans1.size() * m + ans2.size() * m << endl;
    for (auto e : ans1) cout << e;
    			for (auto e : ans2) cout << e;
    			return 0;
}