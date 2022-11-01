#include <iostream>
using namespace std;
int main(){
    int h; long long n;
    cin >> h >> n;
    n--;

    long long cnt = 0;

    while(h) {
        if(n < (1LL << (h - 1))) {
            cnt++;
            n = (1LL << (h - 1)) - n - 1;
        } else {
            cnt += 1LL << h;
            n -= 1LL << (h - 1);
        }
        h--;
    }

    cout << cnt << endl;
}