#include <iostream>
using namespace std;

int main() {
    int64_t n, m, k;
    cin >> n >> m >> k;
    int64_t special[m];
    cin >> special[0];
    int64_t next[m];
    for (int i = 1; i < m; i++) {
        cin >> special[i];
        next[i-1] = special[i]-special[i-1];
    }
    int64_t out = 0;
    int64_t ind = 0;
    int64_t offset = 0;
    bool found = true;
    while (ind < m) {
        int64_t tempOff = 0;
        int64_t startIndex = ((special[ind] - offset - 1)/k)*k;
        out++;
        found = false;
        while (special[ind]-offset-startIndex <= k) {
            //cout << out << ' ' << special[ind] << endl;
            ind++;
            tempOff++;
            found = true;
        }
            if (!found) {
                out--;
            }
            offset += tempOff;
           
    }
    cout << out << endl;
}