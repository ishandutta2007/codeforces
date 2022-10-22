#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<unordered_set<int>> sets(k);
        for (int i = 0; i < k; i++) {
            int c;
            cin >> c;
            sets[i] = unordered_set<int>();
            for (int j = 0; j < c; j++) {
                int s;
                cin >> s;
                sets[i].insert(s);
            }
        }
        // first find maximum of all sets
        cout << "? ";
        int totalSize = 0;
        for (auto set : sets) totalSize += set.size();
        cout << totalSize << " ";
        for (auto set : sets) {
            for (auto elem : set) {
                cout << elem << " ";
            }
        }
        cout << "\n";
        cout.flush();
        int maxSets;
        cin >> maxSets;
        int l = 0;
        int r = k - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            cout << "? ";
            int size = 0;
            for (int i = 0; i <= mid; i++) size += sets[i].size();
            cout << size << " ";
            for (int i = 0; i <= mid; i++) {
                for (auto elem : sets[i]) {
                    cout << elem << " ";
                }
            }
            cout << "\n";
            cout.flush();
            int target;
            cin >> target;
            if (target == maxSets) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        cout << "? " << sets[l].size() << " ";
        for (auto elem : sets[l]) cout << elem << " ";
        cout << "\n";
        cout.flush();
        int maxL;
        cin >> maxL;
        int bigSet;
        if (maxL == maxSets) bigSet = l;
        else                 bigSet = r;
        cout << "? " << n - sets[bigSet].size() << " ";
        for (int i = 1; i<= n; i++) {
            if (sets[bigSet].find(i) == sets[bigSet].end()) cout << i << " ";
        }
        cout << "\n";
        cout.flush();
        int maxOthers;
        cin >> maxOthers;
        if (maxOthers > maxSets) {
            cout << "!";
            for (int i = 0; i < k; i++) cout << " " << maxOthers;
            cout << "\n";
        } else {
            cout << "!";
            for (int i = 0; i < k; i++) {
                if (i == bigSet) {
                    cout << " " << maxOthers;
                } else {
                    cout << " " << maxSets;
                }
            }
            cout << "\n";
        }
        cout.flush();
        string s;
        cin >> s;
        if (s != "Correct") return 0;
    }
}