#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <algorithm>
#include <numeric>
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
const int mxN = 1e5+1;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> deg(n);
        vector<int> w(n);
        ll som = 0;
        for(int& i: w) {
            cin >> i;
            som+=i;
        }
        for(int i=0;i<n-1;++i) {
            int a,b; cin >> a >> b;
            deg[a-1]++; deg[b-1]++;
        }
        vector<int> order(n);
        iota(all(order),0);
        sort(all(order), [&](int a, int b) {return w[a]>w[b];});
        int j = 0;
        for(int i=0;i<n-1;++i) {
            cout << som << ' ';
            while(j<n and deg[order[j]]==1) {
                ++j;
            }
            if(j==n) break;
            som+=w[order[j]];
            deg[order[j]]--;
        } cout << endl;
    }
}