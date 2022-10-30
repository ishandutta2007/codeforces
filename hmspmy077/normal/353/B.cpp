#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>

using namespace std;

typedef long long int64;
typedef long long LL;
typedef long double real;
typedef long double LD;

#define mp make_pair
#define PII pair<int, int>
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-8;
const double PI = acos(0.) * 2;
const int lim = 1000000000;
const int inf = ~0U >> 1;

template<class T> T abs(T x){return x < 0 ? -x : x;}

const int N = 105;

queue<int> a[N];
int ans[N + N];
bool use[N];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n + n; ++i)
    {
        int x;
        cin >> x;
        a[x].push(i);
    }
    int a1 = 0, a2 = 0;
    for (int i = 10; i < 100; ++i)
    {
        if (sz(a[i]) < 2) continue;

        use[i] = true;
        
        ans[a[i].front()] = 1;
        a[i].pop();

        ans[a[i].front()] = 2;
        a[i].pop();
        
        ++a1;
        ++a2;
    }
    for (int i = 10; i < 100; ++i)
    {
        if (use[i]) continue;
        if (!a[i].empty())
        {
            if (a1 == a2) ans[a[i].front()] = 1, ++a1;
            else ans[a[i].front()] = 2, ++a2;
            a[i].pop();
        }
    }
    cout << a1 * a2 << endl;
    for (int i = 0; i < n + n; ++i)
    {
        if (i) cout << ' ';
        if (ans[i] == 0)
        {
            if (a1 < n) ans[i] = 1, ++a1;
            else ans[i] = 2, ++a2;
        }
        cout << ans[i];
    }
    cout << endl;
    return 0;
}