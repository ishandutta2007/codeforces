#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int lng = 0;
    int start = 0;
    int curr = 0;
    bool zero = false;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            zero = true;
            lng = max(lng, curr);
            curr = 0;
        } else {
            curr++;
            if (!zero) {
                start++;
            }
        }
    }
    lng = max(lng, curr+start);
    cout << lng << endl;
}