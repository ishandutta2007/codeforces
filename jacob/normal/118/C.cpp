#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;


int main(void) {
    int n, k;
    string str;
    cin >> n >> k >> str;
    vector < vector<int> > pos(10);
    for (int i = 0; i < n; i++)
        pos[str[i] - '0'].push_back(i);
    typedef pair<int, string> pis;
    pis res = pis(10000000, "");
    for (int dig = 0; dig < 10; dig++) {
        string cr = str;
        int cc = 0;
        int toDo = k - (int)pos[dig].size();
        for (int i = 1; toDo > 0; i++) {
            if (dig + i < 10) {
                for (int j = 0; j < (int)pos[dig+i].size() && toDo > 0; j++) {
                    cr[pos[dig+i][j]] = '0' + dig;
                    --toDo;
                    cc += i;
                }
            }
            if (dig - i >= 0) {
                for (int j = 0; j < (int)pos[dig-i].size() && toDo > 0; j++) {
                    cr[pos[dig-i][pos[dig-i].size() - j - 1]] = '0' + dig;
                    --toDo;
                    cc += i;
                }
            }
        }
        res = min(res, pis(cc, cr));
    }
    cout << res.first << endl << res.second << endl;
    return 0;
}