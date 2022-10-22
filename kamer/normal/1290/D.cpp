#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << "! 1\n";
        cout.flush();
        return 0;
    }
    
    vector<bool> newCoffee(n, true);
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cout << "? " << i + 1 << "\n";
                cout.flush();
                char c;
                cin >> c;
                cout << "? " << j + 1 << "\n";
                cout.flush();
                cin >> c;
                if (c == 'Y') newCoffee[j] = false;
                cout << "R\n";
                cout.flush();
            }
        }
    } else {
        int batchSize = k / 2;
        int numBatches = 2 * n / k;
        for (int dist = 1; dist < numBatches; dist++) {
            for (int batchIndex = 0; batchIndex < min(dist, numBatches - dist); batchIndex++) {
                for (int currBatchIndex = batchIndex; currBatchIndex < numBatches; currBatchIndex += dist) {
                    for (int index = 0; index < batchSize; index++) {
                        int currNum = currBatchIndex * batchSize + index;
                        cout << "? " << currNum + 1 << "\n";
                        cout.flush();
                        char c;
                        cin >> c;
                        if (c == 'Y') {
                            newCoffee[currNum] = false;
                        }
                    }
                }
                cout << "R\n";
                cout.flush();
            }
        }
    }

    int numCoffees = 0;
    for (auto coffee : newCoffee) {
        if (coffee) numCoffees++;
    }

    cout << "! " << numCoffees << "\n";
    cout.flush();
}