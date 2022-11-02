#include <iostream>
using namespace std;

int main()
{
    int c = 0, d = 0;
    cout<< "? " << 0 << " " << 0 << endl;
    int r; cin >> r;
    int a = 0, b = 0;
    for (int i = (1<<29); i >= 1; i /= 2) {
        cout << "? " << c + i << " " << d + i << endl;
        int t; cin >> t;
        if (r == t) {
            cout << "? " << c + i << " " << d << endl;
            int rt; cin >> t;
            if (t == -1){
                a += i; b += i;
            }
        }
        else {
            if (t == 1) {
                b += i; d += i;
            }
            else {
                a += i; c += i;
            }
            cout << "? " << c << " " << d << '\n';
            cin >> r;
        }
    }
    cout << "! " << a << " " << b << '\n';
    return 0;
}