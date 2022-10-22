#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;

vector<vector<tuple<int, int>>> resultsCache;
vector<vector<bool>> checked;

int distance(vector<bool> target, vector<bool> current) {
    int res = 0;
    for (int i = 0; i < 7; i++) {
        if (target[i] && !current[i]) res++;
        if (!target[i] && current[i]) return -1;
    }
    return res;
}

void findMaxNumber(vector<vector<bool>>& digits, vector<vector<bool>>& panel, int startingPos, int numBroken) {
    if (numBroken < 0) {
        return;
    }
    
    if (checked[startingPos][numBroken]) {
        return;
    }

    checked[startingPos][numBroken] = true;
    
    if (startingPos == panel.size()) {
        if (numBroken == 0) {
            resultsCache[startingPos][numBroken] = make_tuple(1, 0);
            return;
        } else {
            resultsCache[startingPos][numBroken] = make_tuple(0, -1);
            return;
        }
    }
    

    for (int digit = 9; digit >= 0; digit--) {
        int dist = distance(digits[digit], panel[startingPos]);
        if (dist < 0) continue;
        if (numBroken < dist) continue;
        findMaxNumber(digits, panel, startingPos + 1, numBroken - dist);
        auto tentative = resultsCache[startingPos + 1][numBroken - dist];
        if (get<1>(tentative) >= 0) {
            resultsCache[startingPos][numBroken] = make_tuple(digit, numBroken - dist);
            return;
        }
    }

    resultsCache[startingPos][numBroken] = make_tuple(0, -1);
    return;
}

int main(void) {
    vector<string> theirDigits = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
    vector<vector<bool>> digits(10, vector<bool>(7, false));
    for (int i = 0; i <= 9; i++) {
        string digit = theirDigits[i];
        for (int j = 0; j < 7; j++) {
            if (digit[j] == '1') digits[i][j] = true;
        }
    }
    int n, k;
    cin >> n >> k;
    resultsCache = vector<vector<tuple<int, int>>>(n + 1, vector<tuple<int, int>>(k + 1, make_tuple(-1, -1)));
    checked = vector<vector<bool>>(n + 1, vector<bool>(k + 1, false));
    vector<vector<bool>> panel(n, vector<bool>(7, false));
    for (int i = 0; i < n; i++) {
        string digit;
        cin >> digit;
        for (int j = 0; j < 7; j++) {
            if (digit[j] == '1') panel[i][j] = true;
        }
    }

    vector<vector<int>> distCache(n, vector<int>(10, -1));
    for (int i = 0; i < n; i++) {
        for (int d = 0; d <= 9; d++) {
            distCache[i][d] = distance(digits[d], panel[i]);
        }
    }

    resultsCache[n][0] = make_tuple(0, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int b = 0; b <= k; b++) {
            for (int d = 9; d >= 0; d--) {
                int dist = distCache[i][d];
                if (dist >= 0 && b >= dist && get<1>(resultsCache[i + 1][b - dist]) >= 0) {
                    resultsCache[i][b] = make_tuple(d, b - dist);
                    break;
                }
            }
        }
    }

    int currNumBroken = k;
    for (int i = 0; i < n; i++) {
        if (get<1>(resultsCache[i][currNumBroken]) < 0) {
            cout << "-1";
            break;
        } else {
            cout << get<0>(resultsCache[i][currNumBroken]);
            currNumBroken = get<1>(resultsCache[i][currNumBroken]);
        }
    }
    cout << "\n";
}