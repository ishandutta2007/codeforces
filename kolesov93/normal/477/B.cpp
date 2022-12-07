#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>

using namespace std;

vector< vector<int> > a;

int gcd(int a, int b) {
    while (a && b)
        if (a > b) a %= b;
        else b %= a;
    return a + b;
}

bool was[1111111];

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(2);
    tmp.push_back(3);
    tmp.push_back(5);
    vector< vector<int> > a;
    a.push_back(tmp);
    int last = 5;
    was[1] = was[2] = was[3] = was[5] = 1;
    vector<int> cands;
    cands.push_back(2);
    while (a.size() < n) {
        vector<int> b;
        b.push_back(last + 2);
        b.push_back(last + 4);
        b.push_back(last + 6);
        cands.push_back(last + 1);
        cands.push_back(last + 3);
        cands.push_back(last + 5);
        last += 6;
        bool cool = false;
        for (int i = 0; i < cands.size(); ++i) {
            int num = cands[i];
            if (!was[num]) {
                bool may = true;
                for (int j = 0; j < b.size(); ++j) {
                    if (gcd(num, b[j]) != 1) {
                        may = false;
                        break;
                    }
                }
                if (!may) continue;
                b.push_back(num);
                cands[i] = cands.back();
                cands.pop_back();
                cool = true;
                break;
            }
        }
        a.push_back(b);
    }

    int ans = last * k;
    printf("%d\n", ans);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) printf("%d ", a[i][j] * k);
        puts("");
    }

    return 0;
}