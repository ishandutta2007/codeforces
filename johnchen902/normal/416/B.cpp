#include <iostream>
#include <vector>

using namespace std;

vector<unsigned> out;

int main() {
    unsigned m, n, x[6] = {};
    cin >> m >> n;
    for(unsigned i = 0; i < m; i++){
        for(unsigned j = 1; j <= n; j++){
            unsigned a; cin >> a;
            x[j] = max(x[j], x[j - 1]) + a;
        }
        out.push_back(x[n]);
    }
    cout << out.front();
    for(unsigned i = 1; i < m; i++)
        cout << " " << out[i];
    cout << endl;
}