#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    char prev;
    cin >> prev;
    int cnt = 1;
    long long posi = 1; // warning

    for(char c; cin >> c; ){
        if(prev + c == '0' + '9'){
            cnt++;
        } else {
            if(cnt % 2){
                posi *= (cnt / 2 + 1);
            }
            cnt = 1;
        }
        prev = c;
    }
    if(cnt % 2){
        posi *= (cnt / 2 + 1);
    }
    cout << posi << endl;
    return 0;
}