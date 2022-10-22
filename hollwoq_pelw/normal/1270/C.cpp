#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        unsigned long long n,a,sum=0,sxor=0;
        cin >> n;
        while(n){
            n--;
            cin >> a;
            sum+=a;
            sxor^=a;
        }
        cout << 2 << endl << sxor << ' ' << sxor+sum << endl;
    }
    return 0;
}