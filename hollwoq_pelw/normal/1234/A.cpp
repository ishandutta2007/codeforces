#include <iostream>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q){
        q--;
        int n,s=0,k;
        cin >> n;
        s = n-1;
        for (int i = 0; i < n; i ++){
            cin >> k;
            s += k;
        }
        cout << s/n << endl;
    }
}