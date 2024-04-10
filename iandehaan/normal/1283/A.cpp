#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int h, m;
        cin >> h >> m;
        int hoursleft = 24 - h - 1;
        int minutesleft = 60 - m;
        cout << minutesleft + hoursleft*60 << endl;
    }
}