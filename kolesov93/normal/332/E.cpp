#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acosl(-1.);
using namespace std;

const int M = 1000111;
const int N = 205;
const int L = 2222;
char p[M], s[N];
int lp, ls;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    gets(p);
    gets(s);
    int k;
    scanf("%d", &k);
    lp = strlen(p);
    ls = strlen(s);

    if (k >= lp) {
        vector<int> ans;
        for (int i = lp; i < k; ++i) ans.push_back(0);

        int pos = ls - 1;
        for (int i = lp - 1; i >= 0; --i) {
            if (pos < 0) {
                ans.push_back(0);
                continue;
            }
            if (p[i] == s[pos]) {
                ans.push_back(1);
                pos--;
            } else {
                ans.push_back(0);
            }
        }
        
        if (pos < 0) {
            while (ans.size() < k) ans.push_back(0);
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < k; ++i) putchar('0' + ans[i]);
            puts("");
        } else {
            puts("0");
        }

        return 0;
    }

    string curans;
    for (int i = 0; i <= k; ++i) curans += '1';

    for (int cnt = 1; cnt <= ls; ++cnt) {
        vector< string > parts(cnt);
        int cur = 0;
        for (int i = 0; i < ls; ++i) {
            parts[cur] += s[i];
            cur = (cur + 1) % cnt;
        }

        vector<int> ans;
        int pos = cnt - 1;
        for (int i = k - 1; i >= 0; --i) {
            if (pos < 0) {
                ans.push_back(0);
                continue;
            }

            int len = lp / k;
            if (i < (lp % k)) ++len;

            if (len != parts[pos].size()) {
                ans.push_back(0);
                continue;
            }

            string result;
            int cpos = i;
            for (int j = 0; j < len; ++j) {
                result += p[cpos];
                cpos += k; 
            }

            if (result == parts[pos]) {
                ans.push_back(1);
                --pos;
            } else {
                ans.push_back(0); 
            }
        }

        if (pos < 0) {
            string result;
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); ++i) {
                result += char(ans[i] + '0');
            }
            if (result < curans) curans = result;
        }
    }

    if (curans.size() == k) cout << curans << endl;
    else puts("0");

    return 0;
}