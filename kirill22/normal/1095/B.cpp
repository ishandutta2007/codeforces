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

int main() {

    ll b,c,x,y,z,x1,y1,ans=0,co=0,n,m,k;

    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin >>k;
        a.push_back(k);
    }

    sort(a.begin(),a.end());
    if (n==2){
        cout << 0;
        return 0;
    }
    cout << min(a[n-1]-a[1],a[n-2]-a[0]);






    return 0;
}