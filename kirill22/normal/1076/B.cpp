#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
inline void Routine() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
template<class T>
istream &operator >> (istream &in, vector<T> &v) {
    for (auto &i : v) {
        in >> i;
    }
    return in;
}

template<class T>
ostream &operator << (ostream &out, const vector<T> &v) {
    for (auto &i : v) {
        out << i << ' ';
    }
    return out;
}


int main() {
    Routine();
    ll n, t,co=0,ans=0,x=0,y=0,b,k;
    cin >> n ;
    if (n%2==0){
        cout << n/2;
        return 0;
    }
    else{
        for(ll i=2;i<=sqrt(n);i++){
            if (n%i==0){
                co=i;
                break;
            }
        }
        if (co==0){
            cout << 1;
            return 0;
        }
        cout << 1+(n-co)/2;
    }





    return 0;
}