#include <iostream>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q){
        q--;
        int n;
        cin >> n;
        long int a,s=0;
        for (int i = 0; i < n; i++){
            cin >> a;
            if (a <= 2048){
                s += a;
            }
        }
        if (s >= 2048){
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}