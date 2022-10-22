#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
vector<vector<bool>> isPossible(500);

void refreshPossible() {
    for (int i = 0; i < 500; i++) {
        isPossible[i] = vector<bool>((i + 1) * 1000 + 1, false);
    }
}

tuple<vector<int>, vector<int>> findSubset(int h, vector<int> &l) {
    // assumes isPossible filled with false
    isPossible[0][0] = true;
    isPossible[0][l[0]] = true;
    int sum = l[0];
    for (int i = 1; i < h; i++) {
        sum += l[i];
        for (int j = 0; j <= i * 1000; j++) {
            if (isPossible[i - 1][j]) {
                isPossible[i][j] = true;
                isPossible[i][j + l[i]] = true;
            }
        }
    }

    vector<bool> inSet(h, false);
    if (sum % 2 == 1) {
        return tuple<vector<int>, vector<int>>(vector<int>(), vector<int>());
    }

    int target = sum / 2;
    if (!isPossible[h - 1][target]) {
        return tuple<vector<int>, vector<int>>(vector<int>(), vector<int>());
    }

    int currentTarget = target;
    for (int i = h - 1; i >= 0; i--) {
        if (currentTarget == l[i]) {
            inSet[i] = true;
            break;
        }
        if (currentTarget > l[i] && isPossible[i - 1][currentTarget - l[i]]) {
            inSet[i] = true;
            currentTarget -= l[i];
        }
    }

    vector<int> f, s;
    for (int i = 0; i < h; i++) {
        if (inSet[i]) f.push_back(l[i]);
        else s.push_back(l[i]);
    }
    if (f.size() < s.size()) swap(f, s);
    return make_tuple(f, s);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int h, v;
        cin >> h;
        vector<int> l(h);
        for (int i = 0; i < h; i++) cin >> l[i];
        cin >> v;
        vector<int> p(v);
        for (int i = 0; i < v; i++) cin >> p[i];
        if (v != h) {
            cout << "No" << endl;
            continue;
        }
        refreshPossible();
        auto [fH, sH] = findSubset(h, l);
        if (fH.size() == 0) {
            cout << "No" << endl;
            continue;
        }
        refreshPossible();
        auto [fV, sV] = findSubset(v, p);
        if (fV.size() == 0) {
            cout << "No" << endl;
            continue;
        }
        sort(sH.begin(), sH.end(), greater<int>());
        sort(sV.begin(), sV.end(), greater<int>());
        sort(fH.begin(), fH.end());
        sort(fV.begin(), fV.end());
        
        cout << "Yes" << endl;
        cout << "0 0" << endl;
        int currX = 0, currY = 0;
        for (int i = 0; i < sH.size(); i++) {
            currX += sH[i];
            cout << currX << " " << currY << endl;
            currY += fV[i];
            cout << currX << " " << currY << endl;
        }
        for (int i = sH.size(); i < fV.size(); i++) {
            currX -= fH[fH.size() + sH.size() - i - 1];
            cout << currX << " " << currY << endl;
            currY += fV[i];
            cout << currX << " " << currY << endl;
        }
        for (int i = sV.size() - 1; i >= 0; i--) {
            currX -= fH[i];
            cout << currX << " " << currY << endl;
            currY -= sV[i];
            if (i > 0) cout << currX << " " << currY << endl;
        }
    }
}