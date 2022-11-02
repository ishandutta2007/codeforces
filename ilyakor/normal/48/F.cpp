#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

vector<double> delta;

const int maxn = 500 * 1000 + 10;

pair<double, pair<int, ii> > v[maxn];

int w[maxn];
int c[maxn];
int a[maxn];

double dl[maxn];

int n, m, W;

void quickSort(pair<double, pair<int, ii> > arr[], int left, int right, int W) {
    while (left < right)
    {
        int i = left, j = right;
        int tmp;
        double pivot = arr[(left + right) / 2].first;
        while (i <= j) 
        {
            while (arr[i].first < pivot) i++;
            while (arr[j].first > pivot) j--;
            if (i <= j) 
            {
                swap(arr[i], arr[j]);
                ++i, --j;
            }
        }
        int sum = W;
        for (int t = left; t < i; ++t)
            if (sum >= 0)
                sum -= arr[t].second.first;
        if (sum > 0)
        {
            if (j < right)
                quickSort(arr, i, right, sum);
            break;
        }
        right = j;
    }
}

inline bool cmp(pair<double, pair<int, ii> > p, pair<double, pair<int, ii> > q)
{
    return p.first < q.first;
}

int main()
{
    cin >> n >> m >> W;
    delta.resize(m);
    for (int i = 0; i < m; ++i)
        scanf("%d", &w[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &c[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
    {
        delta[i] = -(a[i] + 0.) / w[i];
        v[i].first = (c[i] + 0.) / w[i];
        v[i].second = mp(w[i], ii(a[i], c[i]));
    }
    double res = 0.0;
    int64 ipart = 0;
    for (int it = 0; it < n; ++it)
    {
        /*for (int i = 0; i < m; ++i)
            dl[i] = (c[i] - a[i] * it + 0.) / w[i];
        sort(dl, dl + m);*/
        
        //sort(v, v + m/*, cmp*/);
        quickSort(v, 0, m - 1, W);
        int cur = W;
        for (int i = 0; i < m; ++i)
        {
            if (cur >= v[i].second.first)
            {
                cur -= v[i].second.first;
                ipart += v[i].second.second.second - v[i].second.second.first * it;
            }
            else
            {
                int64 tmp = cur * (int64) (v[i].second.second.second - v[i].second.second.first * it);
                ipart += tmp / v[i].second.first;
                res += (tmp % v[i].second.first + 0.) / v[i].second.first;
                cur = 0;
                break;
            }
        }
        for (int i = 0; i < m; ++i)
            v[i].first -= (v[i].second.second.first + 0.0) / v[i].second.first;
    }
    int64 tmp = (int64) res;
    ipart += tmp;
    res -= tmp;
    char buf[100];
    sprintf(buf, "%.10lf\n", res);
    cout << ipart;
    int t = 0;
    while (buf[t] != '.') ++t;
    while (buf[t])
        printf("%c", buf[t++]);
    return 0;
}