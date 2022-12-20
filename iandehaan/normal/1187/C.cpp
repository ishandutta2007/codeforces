#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int preprocess[n];
    unordered_set<int> breaks;
    for (int i = 0; i < n; i++) {
        preprocess[i] = 0;
    }
    int ind = 1;
    vector<pair<int, int>> acs;
    for (int i = 0; i < m; i++) {
        int action, start, end;
        cin >> action >> start >> end;
        if (action == 0) {
            acs.push_back(make_pair(start, end));
        } else {
            unordered_set<int> updateInds;
            for (int j = start-1; j < end; j++) {
                if (preprocess[j] != 0) {
                    updateInds.insert(preprocess[j]);
                }
                preprocess[j] = ind;
            }
            for (int j = 0; j < n; j++) {
                if (updateInds.find(preprocess[j]) != updateInds.end()) {
                    preprocess[j] = ind;
                }
            }
            ind++;
        }
    }
    for (auto iter = acs.begin(); iter != acs.end(); iter++) {
        pair<int, int> action = *iter;
        int start = action.first;
        int end = action.second;

        bool found = false;
        for (int i = start; i < end; i++) {
            if (preprocess[i] == 0 || preprocess[i-1] == 0 || preprocess[i] != preprocess[i-1]) {
                breaks.insert(i);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "NO" << endl;
            return 0;
        }
    }

    int val = 1001;
    int out[n];
    for (int i = 0; i < n; i++) {
        if (breaks.find(i) != breaks.end()) {
            val--;
        } else {
            val++;
        }
        out[i] = val;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n-1; i++) {
        cout << out[i] << ' ';
    }
    cout << out[n-1] << endl;
}