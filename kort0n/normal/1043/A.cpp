#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    int a[105];
    int k = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
        k = max(k, a[i]);
    }
    while(true){
        if(n * k - sum > sum){
            cout << k << endl;
            return 0;
        }
        k++;
    }
    return 0;
}