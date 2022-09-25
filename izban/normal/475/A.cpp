#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 200200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    int k;
    while (cin >> k) {
        string s[6];
        s[0] = "+------------------------+";
        s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
        s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
        s[3] = "|#.......................|";
        s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
        s[5] = "+------------------------+";    
        for (int j = 0; j < (int)s[0].length(); j++) {
            for (int i = 0; i < 6; i++) {
                if (s[i][j] == '#' && k) {
                    s[i][j] = 'O';
                    k--;
                }
            }
        }
        for (int i = 0; i < 6; i++) cout << s[i] << endl;
    }
    
    return 0;
}