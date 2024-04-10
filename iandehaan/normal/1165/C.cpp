#include <iostream>
using namespace std;
bool us[210000];

int main() {
    int n;
    cin >> n;
    char in[n];
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        us[i] = true;
    }

    int stoppedUsing = 0;
    for (int i = 0; i < n-1; i++) {
        if (!us[i]) {
            continue;
        }
        if (((i+1) % 2 == 0 && stoppedUsing % 2 == 1) || ((i+1) % 2 ==1 && stoppedUsing % 2 == 0)) {
            if (in[i] == in[i+1]) {
                // stop using i+1
                int ind = i+1;
                while (in[ind] == in[i]) {
                    us[ind] = false;
                    stoppedUsing++;
                    if (ind < n-1) {
                        ind++;
                    } else {
                        break;
                    }
                }
            }
        } 
    }
    if ((n-stoppedUsing) % 2 == 1) {
        // remove last
        stoppedUsing++;
        for (int i = n-1; i >= 0; i--) {
            if (us[i]) {
                us[i] = false;
                break;
            }
        }
    }
    cout << stoppedUsing << endl;
    for (int i = 0; i < n; i++) {
        if (us[i]) {
            cout << in[i];
        }
    }
    cout << endl;
}