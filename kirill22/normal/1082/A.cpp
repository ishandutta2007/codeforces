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

    int n,m,k,L,R,ans=0,co=0;
    string s;
    int t;
    cin >> t ;

    for(int i=0;i<t;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        if (c%d!=1 && c%d!=a%d && c%d!=b%d){
            cout << -1 << endl;
            continue;
        }
        if (c%d==b%d){
            cout << abs(c-b)/d << endl;
        }
        else if (c%d==1 && c%d==a%d){
            int ans=((abs(1-c)))/d+(abs(1-b)+d-1)/d;
            cout << min(ans,(abs(a-c))/d +(abs(a-b)+d-1)/d) << endl;
        }
        else if (c%d==1){
            cout << ((abs(1-c)))/d+(abs(1-b)+d-1)/d << endl;
        }
        else{
            cout << ((abs(a-c)))/d +(abs(a-b)+d-1)/d<< endl;
        }
    }





    return 0;
}