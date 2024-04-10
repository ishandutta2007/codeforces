#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> occ[26];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        occ[c-'a'].push_back(i);
    }
    int m;
    cin >> m;
    for (int cs = 0; cs < m; cs++) {
        string target;
        cin >> target;
        int cnt[26];
        for (int i = 0; i < 26; i++) {
            cnt[i] = 0;
        }
        for (char c: target) {
            cnt[c-'a']++;
        }
        int out = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                out = max(out, occ[i][cnt[i]-1]);
            }
        }
        cout << out+1 << endl;
    }
}