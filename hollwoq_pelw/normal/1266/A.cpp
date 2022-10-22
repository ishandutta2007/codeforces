#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n){
        n--;
        string s;
        cin >> s;
        int sum = 0, even = 0, zero = 0;
        for(char c:s){
            int k = c-'0';
            sum += k;
            if (k%2==0) even++;
            if (k == 0) zero++;
        }
        if (sum%3==0 && even > 1 && zero > 0) cout << "red" << endl;
        else cout << "cyan" << endl;
    }
    return 0;
}