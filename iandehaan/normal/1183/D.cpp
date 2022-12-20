#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int cs = 0; cs < q; cs++) {
        int n;
        cin >> n;
        unordered_map<int, int> candies;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (candies.find(x) == candies.end()) {
                candies[x] = 1;
            } else {
                candies[x]++;
            }
        }
        vector<int> sorto;
        for (auto iter = candies.begin(); iter != candies.end(); iter++) {
            sorto.push_back((*iter).second);
        }
        sort(sorto.begin(), sorto.end());
        int used = __INT_MAX__;
        uint64_t out = 0;
        for (int i = sorto.size()-1; i >= 0; i--) {
            if (used == 1) {
                break;
            }
            if (sorto[i] < used) {
                out += sorto[i];
                used = sorto[i];
            } else {
                out += used-1;
                used--;
            }
        }
        cout << out << endl;
    }
}