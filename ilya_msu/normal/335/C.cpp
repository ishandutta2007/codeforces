#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
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

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 500000;
//const int N = 1000 * 1000 * 1000 + 10;

vector<vector<vector<int> > > nim;
int get(int r, int m1, int m2) {
    if (r == 0)
        return 0;
   if (nim[r][m1][m2] != -1)
       return nim[r][m1][m2];
   vector<int> used(250, false);
   vector<vector<int> > pos(r, vector<int> (2, true));
   if (m1 == 1)
       pos[0][1] = false;
   if (m1 == 2)
       pos[0][0] = false;
   if (m2 == 1)
       pos[r - 1][1] = false;
   if (m2 == 2)
       pos[r - 1][0] = false;
   for (int i = 0; i < 2; ++i) {
       for (int j = 0; j < r; ++j) {
           if (!pos[j][i])
               continue;
           int cur = get(j, m1, i + 1) ^ get(r - j - 1, i + 1, m2);
           if (cur < used.size())
               used[cur] = true;
       }
   }
   for (int i = 0; i < used.size(); ++i) {
       if (!used[i]) {
           nim[r][m1][m2] = i;
           return i;
       }
   }
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int r, n;
    cin >> r >> n;
    nim.assign(r + 1, vector<vector<int> >(3, vector<int>(3, -1)));
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    a.push_back(pii(0, 0));
    a.push_back(pii(r + 1, 0));
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 1; i < a.size(); ++i)
        res = res ^ get(a[i].first - a[i - 1].first - 1, a[i - 1].second, a[i].second);
    if (res)
        cout << "WIN" << endl;
    else
        cout << "LOSE" << endl;
    return 0;
}