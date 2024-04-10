#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

uint64_t hsh(string x) {
    uint64_t out = 0;
    for (char c : x) {
        out *= 27;
        out += c - 'A' + 1;
    }
    return out;
}

int main() {
    unordered_map<uint64_t, int> my_set;
    int n, k;
    cin >> n >> k;
    string inputs[n];
    for (int i = 0; i < n; i++) {
        string inp;
        cin >> inp;
        uint64_t inphsh = hsh(inp);
        if (my_set.find(inphsh) == my_set.end()) {
            my_set[inphsh] = 0;
        }
        my_set[inphsh]++;
        inputs[i] = inp;
    }

    int64_t out = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            //cout << i << ' ' << j << endl;
            char needed[k];
            for (int l = 0; l < k; l++) {
                char used1 = inputs[i][l];
                char used2 = inputs[j][l];
                if (used1 == used2) {
                    needed[l] = used1;
                } else {
                    if (used1 != 'S' && used2 != 'S') {
                        needed[l] = 'S';
                    }
                    if (used1 != 'E' && used2 != 'E') {
                        needed[l] = 'E';
                    }
                    if (used1 != 'T' && used2 != 'T') {
                        needed[l] = 'T';
                    }
                }
            }

            uint64_t neededhsh = 0;
            for (int l = 0; l < k; l++) {
                neededhsh *= 27;
                neededhsh += needed[l] - 'A' + 1;
            }

            //cout << neededstr << endl;

            if (my_set.find(neededhsh) != my_set.end()) {
                if (inputs[i] != inputs[j]) {
                    out += my_set[neededhsh];
                } else {
                    out += max(my_set[neededhsh]-2, 0);
                }
            }


        }    
    }
    cout << out/6 << endl;
}