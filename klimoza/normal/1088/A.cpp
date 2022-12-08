#include <iostream>

using namespace std;

int main(){
    int x;
    cin >> x;
    if(x <= 1){
        cout << -1 << endl;
        return 0;
    }
    cout << (x / 2) * 2 << " " << 2 << endl;
    return 0;
}