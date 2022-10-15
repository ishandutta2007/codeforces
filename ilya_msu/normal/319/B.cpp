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
const int INF = 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 7;



int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n;
    //scanf("%d", &n);
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        //scanf("%d", &a[i]);
        cin >> a[i];
        b[i] = a[i];
    }
    queue<int> q;
    vector<int> act(n - 1), pos(n);
    vector<bool> alive(n, 1);
    for (int i = 0; i < n - 1; ++i) {
        pos[i] = act[i] = i;
    }
    pos[n - 1] = n - 1;
    int res = -1;
    bool kill = true;
    while(kill) {
        kill = false;
        ++res;
        vector<int> newAct;
        for (int i = 0; i < act.size(); ++i) {
            int v = act[i];
            int r = pos[v];
            while(r + 1 < n) {
                if (!alive[r + 1])
                    ++r;
                else
                    break;
            }
            if (r + 1 == n) {
                continue;
            }
            if (a[r + 1] > a[v])
                continue;
            kill = true;
            alive[r + 1] = 0;
            if (alive[v])
                newAct.push_back(v);
            pos[v] = r + 1;
        }
        for (int i = act.size() - 1; i >= 0; --i) {
            int x = pos[act[i]];
            if (x == n)
                continue;
            pos[act[i]] = pos[x];
        }
        act = newAct;
    }
   
    cout << res << endl;
    return 0;
}