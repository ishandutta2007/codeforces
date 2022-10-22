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
const long double  MOD=1e-6;
long double a[200];
int main() {
    for(int i=1;i<189;i++){
        a[i]=-1;

    }

    for( int i=1;i<189;i++){
        for( long double u=3;u<=180;u++){
            long double ii=i;
            if (ii<=(180*(u-2))/u && (ii/(180/u)-int (ii/(180/u)))<MOD){
                a[i]=u;


                break;
            }
        }



    }

    int n,m,x,y,x1,y1;
    cin >> n;
    for( long double i=0;i<n;i++){
        cin >> m;
        if (m==179){
            cout << 360 << endl;
            continue;
        }
       cout << a[m] << endl;

    }








    return 0;
}