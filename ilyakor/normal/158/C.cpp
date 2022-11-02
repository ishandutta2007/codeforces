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

int main()
{
    int n;
    vector<string> cur;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;

        if (cmd == "pwd") {
            printf("/");
            for (int i = 0; i < sz(cur); ++i)
                cout << cur[i] << "/";
            cout << "\n";
        } else {
            string arg;
            cin >> arg;
            if (sz(arg) && arg[0] == '/') cur.clear();
            for (int i = 0; i < sz(arg); ++i) 
                if (arg[i] == '/') arg[i] = ' ';

            stringstream ss(arg);
            string s;
            while (ss >> s) {
                if (s == ".") continue;
                if (s == "..") {
                    if (sz(cur)) cur.pop_back();
                    continue;
                }

                cur.pb(s);
            }
        }
    }
    return 0;
}