#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> candies[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        candies[a].push_back(b);
    }
    int scores[n];
    for (int i = 0; i < n; i++) {
        if (candies[i].size() == 0) {
            scores[i] = 0;
        } else {
            scores[i] = n*(candies[i].size()-1);
            int smallest = 1e9;
            for (int c : candies[i]) {
                int dist = c-i;
                while (dist < 0) {
                    dist += n;
                }
                dist %= n;
                smallest = min(smallest, dist);
            }
            scores[i] += smallest;
        }
    }

    int outVals[n];

    for (int i = 0; i < n; i++) {
        int out = scores[i];
        int dist = 1;
        int j = (i+1)%n;
        while (j != i) {
            if (scores[j] == 0) {
                dist++;
                j++;
                j %= n;
                continue;
            }
            int fromHere = dist + scores[j];
            out = max(out, fromHere);
            dist++;
            j++;
            j %= n;
        }
        outVals[i] = out;
    }
    for (int i = 0; i < n-1; i++) {
        cout << outVals[i] << ' ';
    }
    cout << outVals[n-1] << endl;
}