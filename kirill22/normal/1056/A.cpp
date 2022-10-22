#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
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
const long long MOD=1e9+7;
int main() {
    ll a,b,c,x,y,z,ans=0,co=0,n,k,L=0,R=0;
    cin >> n;
    int used[1000]={0};
    for(int i=0;i<n;i++){
        cin >> k;
        for(int o=0;o<k;o++){
            cin >> a;
            used[a]++;
        }
    }
    for(int i=0;i<200;i++){
        if (used[i]==n){
            cout << i << " ";
        }

    }



    return 0;
}