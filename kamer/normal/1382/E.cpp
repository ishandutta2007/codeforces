#include <iostream>
#include <algorithm>
#include <utility>
#include <tuple>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        y = y - x;
        vector<int> b(n);
        vector<bool> seen(n + 1, false);
        vector<vector<int>> colorIndices = vector<vector<int>>(n + 1, vector<int>());
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
            seen[b[i]] = true;
            colorIndices[b[i]].push_back(i);
        }
        int extraColor = -1;
        for (int i = 0; i <= n; i++) {
            if (!seen[i]) {
                extraColor = i;
                break;
            }
        }

        priority_queue<tuple<int, int>> colorSizes;
        vector<int> a(n, extraColor);
        for (int i = 0; i <= n; i++) {
            colorSizes.push(make_tuple(colorIndices[i].size(), i));
        }
        
        // handle x
        for (int i = 0; i < x; i++) {
            auto queueTop = colorSizes.top();
            colorSizes.pop();
            auto size = get<0>(queueTop);
            auto color = get<1>(queueTop);
            a[colorIndices[color][size - 1]] = color;
            size--;
            colorIndices[color].pop_back();
            colorSizes.push(make_tuple(size, color));
        }
        
        // handle y
        int maxSize = 0;
        int maxColor = 0;
        for (int color = 0; color <= n; color++) {
            if (colorIndices[color].size() > maxSize) {
                maxColor = color;
                maxSize = colorIndices[color].size();
            }
        }

        if (y > 2 * (n - x - maxSize)) {
            cout << "NO\n";
            continue;
        }

        if (y == 0) {
            cout << "YES\n";
            for (auto aElem : a) cout << aElem + 1 << " ";
            cout << "\n";
            continue;
        }

        int bColor = (maxColor + 1) % (n + 1);
        int bIndex = 0;

        while (colorIndices[bColor].size() == 0) {
            bColor = (bColor + 1) % (n + 1);
        }
        
        int aColor = bColor;
        int aIndex = 0;
        for (int i = 0; i < maxSize; i++) {
            aIndex++;
            if (aIndex == colorIndices[aColor].size()) {
                aColor = (aColor + 1) % (n + 1);
                while (colorIndices[aColor].size() == 0) aColor = (aColor + 1) % (n + 1);
                aIndex = 0;
            }
        }

        for (int i = 0; i < y; i++) {
            a[colorIndices[aColor][aIndex]] = bColor;
            
            bIndex++;
            if (bIndex == colorIndices[bColor].size()) {
                bColor = (bColor + 1) % (n + 1);
                while (colorIndices[bColor].size() == 0) bColor = (bColor + 1) % (n + 1);
                bIndex = 0;
            }
            
            aIndex++;
            if (aIndex == colorIndices[aColor].size()) {
                aColor = (aColor + 1) % (n + 1);
                while (colorIndices[aColor].size() == 0) aColor = (aColor + 1) % (n + 1);
                aIndex = 0;
            }
        }

        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << a[i] + 1 << " ";
        }
        cout << "\n";

    }
}