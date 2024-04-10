#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,k,a,h=1000000001,m;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> k >> a;
        if (k<a){
            m=k;
            k=a;
            a=m;
        }
        if (h<a){
            cout << "NO";
            return 0;
        }
        else if (h<k){
            h=a;
            continue;
        }
        else {
            h=k;
        }
    }
    cout << "YES";

}