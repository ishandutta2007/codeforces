#include <bits/stdc++.h>
using namespace std;

int main() {
    int ah, am, bh, bm;
    char p1, p2;
    cin >> ah >> p1 >> am;
    cin >> bh >> p2 >> bm;

    int t1, t2;
    t1 = ah*60 + am;
    t2 = bh*60 + bm;
    
    int mid = (t1 + t2) / 2;
    
    int fh = 0, fm = 0;
    fh = mid / 60;
    fm = mid - fh*60;

    if(fh < 10) cout << "0" << fh;
    else cout << fh;

    cout << ":";

    if(fm < 10) cout << "0" << fm;
    else cout << fm;

    return 0;
}