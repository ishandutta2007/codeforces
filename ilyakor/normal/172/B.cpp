#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;

typedef long long int64;
typedef vector<int> vi;
 
int main() {
        int64 a, b, m, r0;
        cin >> a >> b >> m >> r0;
        
        int64 pper, per;
        
        vi u(m, -1);
        int64 r = r0;
        for (int it = 0; ; ++it) {
            if (u[r] != -1) {
                pper = u[r];
                per = it - u[r];
                break;
            }
            
            u[r] = it;
            r = (a * r + b) % m;
        }
        
        cout <</* pper << " " <<*/ per << endl;
        return 0;
}