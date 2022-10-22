#include <iostream>
using namespace std;
int main(){
    long long n;
    cin >> n;
    bool a = true,b = false;
    long long res=0,k;
    for (int i = 0; i < n; i++){
        cin >> k;
        if (k < 0) {
            a = !a;
            res += -1-k;
        }else if (k == 0){ 
            b = true;
            res ++;
        }
        else {
            res += k-1;
        }
    }
    if (!a && !b) res += 2;
    cout << res;
}