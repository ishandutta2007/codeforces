#include <iostream>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        long long x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long dx = abs(x1-x2),dy = abs(y2-y1);
        if(dx==0 or dy ==0) {
            cout << max(dx,dy) << endl;
        } else {
            cout << dx+dy+2 << endl;
        }
    }
}