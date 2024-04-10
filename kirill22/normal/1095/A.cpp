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
    string s;

    cin >> n >> s;
    int ii=0;
    for(int i = 1 ; i <= n;i++){
            int o=i;
            if (ii>=n){

                break;
            }
            cout << s[ii];
            while(o!=0){
                o--;
                ii++;

            }
            }







    return 0;
}