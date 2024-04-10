#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; ++i) {
                cin >> v[i];
        }
        
        int res = 0;
        while (1) {
                bool ok = true;
                for (int i = 0; i < n; ++i)
                        if (v[i].size() < res + 1 || v[i].substr(0, res + 1) != v[0].substr(0, res + 1)) {
                                ok = false;
                                break;
                        }
                if (!ok) break;
                ++res;
        
        }
        
        cout << res << "\n";
        return 0;
}