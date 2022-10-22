#include <iostream>
using namespace std;
int main(){
    long n,a,max;
    cin >> n;
    long long s = 0;
    for(long i = 0; i < n; i++){
        cin >> a;
        s+=a;
        if (i == 0 || max < a){
            max = a;
        }
    }
    if (s%2==0 && max <= s/2) cout << "YES";
    else cout << "NO";
    return 0;
}