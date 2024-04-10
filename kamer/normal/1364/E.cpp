#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int getRand(int n) {
    return rand() % n; 
}

tuple<int, int> get2Rand(int n) {
    int i = getRand(n);
    int j = getRand(n);
    while (j == i) j = getRand(n);
    return make_tuple(i, j);
}

int getDiffRand(int i, int j, int n) {
    int res = getRand(n);
    while (res == i || res == j) res = getRand(n);
    return res;
}

int countBits(int n) {
    if (n == 0) return 0;
    int c = 0;
    while (n > 0) {
        if (n % 2 == 1) c++;
        n = n / 2;
    }
    return c;
}

int main(void) {
    srand(time(NULL));
    int n;
    cin >> n;
    if (n == 3) {
        cout << "? 1 2\n";
        cout.flush();
        int res0; cin >> res0;
        cout << "? 1 3\n";
        cout.flush();
        int res1; cin >> res1;
        cout << "? 2 3\n";
        cout.flush();
        int res2; cin >> res2;
        cout << "! " << 3 - res2 << " " << 3 - res1 << " " << 3 - res0 << "\n";
        cout.flush();
        return 0;
    }
    bool found = false;
    int i, j;
    while (!found) {
        auto tempp = get2Rand(n);
        i = get<0>(tempp), j = get<1>(tempp);
        cout << "? " << i + 1 << " " << j + 1<< "\n";
        cout.flush();
        int res;
        cin >> res;
        if (countBits(res) <= 6) found = true;
    }

    // Now find which one has less than for bits
    found = false;
    while (!found) {
        int q = getDiffRand(i, j, n);
        cout << "? " << i + 1 << " " << q + 1 << "\n";
        cout.flush();
        int resI;
        cin >> resI;
        cout << "? " << j + 1 << " " << q + 1 << "\n";
        cout.flush();
        int resJ;
        cin >> resJ;
        if (countBits(resI) <= 5) found = true;
        if (countBits(resJ) <= 5) {
            i = j;
            found = true;
        }
    }

    // we now know i has at most 4 bits
    vector<int> res(n);
    unordered_set<int> vals;
    for (int k = 0; k < n; k++) {
        if (k != i) {
            cout << "? " << k + 1 << " " << i + 1 << "\n";
            cout.flush();
            cin >> res[k];
            vals.insert(res[k]);
        } else {
            res[k] = 10000;
        }
    }
    
    vector<int> minIndices;
    int minim = 100000;
    for (int k = 0; k < n; k++) {
        if (res[k] < minim) minim = res[k];
    }
    for (int k = 0; k < n; k++) {
        if (res[k] == minim) minIndices.push_back(k);
    }
    if (vals.size() < n - 1 || minim != 1) {

        while (minIndices.size() > 1) {
            if (minIndices.size() == 3) {
                int a = minIndices[0];
                int b = minIndices[1];
                int c = minIndices[2];
                cout << "? " << a + 1 << " " << b + 1 << "\n";
                cout.flush();
                int res0; cin >> res0;
                cout << "? " << b + 1 << " " << c + 1 << "\n";
                cout.flush();
                int res1; cin >> res1;
                cout << "? " << c + 1 << " " << a + 1 << "\n";
                cout.flush();
                int res2; cin >> res2;
                minIndices = vector<int>();
                if (res0 > res1 && res0 > res2) minIndices.push_back(c);
                else if (res1 > res2) minIndices.push_back(a);
                else minIndices.push_back(b);
            }

            int x = minIndices[0];
            unordered_map<int, int> resX;
            unordered_set<int> vals;
            for (int k = 1; k < minIndices.size(); k++) {
                cout << "? " << x + 1 << " " << minIndices[k] + 1 << "\n";
                cout.flush();
                int rr; cin >> rr; resX[minIndices[k]] = rr;
                vals.insert(rr);
            }
            if (vals.size() == minIndices.size() - 1) {
                minIndices = vector<int>();
                minIndices.push_back(x);
            } else {
                
                vector<int> tempInd;
                int minimX = 100000;
                for (auto resXX : resX) {
                    if (minimX > resXX.second) minimX = resXX.second;
                }

                for (int k = 1; k < minIndices.size(); k++) {
                    if (resX[minIndices[k]] == minimX) tempInd.push_back(minIndices[k]);
                }
                minIndices = tempInd;
            }
        }

        i = minIndices[0];
    }

    vector<int> perm(n);
    for (int k = 0; k < n; k++) {
        if (k != i) {
            cout << "? " << k + 1 << " " << i + 1 << "\n";
            cout.flush();
            cin >> perm[k];
        } else {
            perm[k] = 0;
        }
    }
    cout << "! ";
    for (auto permEl : perm) cout << permEl << " ";
    cout << "\n";
    cout.flush();
    
}