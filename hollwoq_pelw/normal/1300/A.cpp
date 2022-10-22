#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        int n,k;
        cin >> n;
        int sum = 0, step = 0;
        for (int i = 0; i < n; i++){
            cin >> k;
            if (k == 0){
                step++;
                sum++;
            }else{
                sum+=k;
            }
        }
        if (sum == 0) step++;
        cout << step << endl;
    }
    return 0;
}