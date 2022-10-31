#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

unsigned c[1000], p[1000], r[1000];

vector<pair<unsigned, unsigned>> out;

int main() {
    unsigned n; cin >> n;
    for(unsigned i = 0; i < n; i++)
        cin >> c[i] >> p[i];
    unsigned k; cin >> k;
    for(unsigned i = 0; i < k; i++)
        cin >> r[i];
    unsigned m = 0, s = 0;
    for(unsigned i = 0; i < k; i++){
//        cerr << i << endl;
        auto x = min_element(r, r + k);
        unsigned a = 0, b = 0;
        for(unsigned j = 0; j < n; j++)
            if(c[j] <= *x && p[j] > b)
                a = j, b = p[j];
        if(b > 0){
            out.push_back({a + 1, x - r + 1});
            m++;
            s+=b;
            c[a] = 99999;
            p[a] = 0;
        }
        *x = 9999;
    }
    cout << m << " " << s << endl;
    for(auto a : out)
        cout << a.first << " " << a.second << endl;
}