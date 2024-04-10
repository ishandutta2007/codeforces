#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, k, a1[100] = {}, a2[100] = {};
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int j;
        cin >> j;
        (j == 1 ? a1 : a2)[i % k]++;
    }
    int sum = 0;
    for(int i = 0; i < k; i++)
        sum += min(a1[i], a2[i]);
    cout << sum << endl;
    return 0;
}