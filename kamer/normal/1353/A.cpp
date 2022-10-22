#include <iostream>
using namespace std;

int main(void) {
    int T;
    cin >> T;
    while(T--) {
        int N, M;
        cin >> N >> M;
        if (N == 1) {
            cout << "0\n";
        } else if (N == 2) {
            cout << M << "\n";
        } else {
            cout << 2 * M << "\n";
        }
        
    }
    return 0;
}