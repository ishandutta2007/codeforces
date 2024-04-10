#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector <int> vi;

const int inf = 1000000000;
const double eps = 0.000001;

struct pt
{
    double x, y;
    int k;
};

bool comp (pt a, pt b)
{
    return (a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y);
}

int main()
{

    int n, s;
    cin >> n >> s;

    vector <pt> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].x >> v[i].y >> v[i].k;

    sort(v.begin(), v.end(), comp);

    cout << fixed;
    cout.precision(6);

    for (int i = 0; i < n; i++)
    {
        s += v[i].k;
        if (s >= 1000000) {cout << sqrt(v[i].x * v[i].x + v[i].y * v[i].y); return 0;}
    }

    cout << "-1";

}