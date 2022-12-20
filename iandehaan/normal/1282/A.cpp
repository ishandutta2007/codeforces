#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        if (b < a) swap(b, a);
        int dist = b-a;
        int rightcoverage, leftcoverage;
        if (c > a) {
            rightcoverage = min(b-c, r);
        } else {
            int dl = a-c;
            rightcoverage = min(b-c, r-dl);
        }
        if (c < b) {
            leftcoverage = min(c-a, r);
        } else {
            int dl = c - b;
            leftcoverage = min(c-a, r-dl);
        }
        //cout << leftcoverage << ' ' << rightcoverage << endl;
        //cout << dist << endl;
        cout << max(0, dist - max(0, rightcoverage) - max(0, leftcoverage)) << endl;
    }
}