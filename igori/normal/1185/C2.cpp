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
using std::min;
using std::max;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return

ll n, a[500000], b[500000];
S s, t;
ll m;
ll cnt[500];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    long long summ = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        long long summ_must_be_less = m - a[i];
        ll s2 = summ;
        long long ans = 0;
        if (s2 > summ_must_be_less)
        for (int j = 100; j >= 1; j--)
        {
            long long skip = cnt[j] * j;
            if (s2 - skip > summ_must_be_less)
            {
                s2 -= skip;
                ans += cnt[j];
            }
            else
            {
                long long need = s2 - summ_must_be_less;
                ans += (need + j - 1) / j;
                s2 -= (need + j - 1) / j * j;
                break;
            }
        }
        cout << ans << " ";
        cnt[a[i]]++;
        summ += a[i];
    }
}