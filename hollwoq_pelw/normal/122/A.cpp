#include <iostream>
using namespace std;
bool lucky(int k){
    while (k){
        if (k%10 != 4 && k%10 != 7) return false;
        k /= 10;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        if (n%i==0 && lucky(i)){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}