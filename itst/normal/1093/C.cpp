#include<iostream>
using namespace std;
const int MAXN =2e5 + 3;
#define int long long
int a[MAXN] , b[MAXN] , N;
signed main(){
    cin >> N;
    for(int i = 1 ; i <= N / 2 ; ++i)
        cin >> b[i];
    a[N + 1] = 1e18;
    for(int i = 1 ; i <= N / 2 ; ++i){
        a[i] = max(a[i - 1] , b[i] - a[N - i + 2]);
        a[N - i + 1] = b[i] - a[i];
    }
    for(int i = 1 ; i <= N ; ++i)
        cout << a[i] << ' ';
    return 0;
}