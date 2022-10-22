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
    ld n, co=0,ans=0,x=0,y=0,k;
    int t;
    cin >> t;
    for(int o=0;o<t;o++){
        cin >> n;
        ld a=n-2.0,b=2.0;
        if (n==4){
            cout << "Y " <<  "2.0000000000" << " " << "2.0000000000" << endl;
            continue;
        }
        
        if (n==1){
            cout << "N" << endl;
            continue;
        }
        for(int i=0;i<12;i++){
            ld k=1;
            int z=0;
            for(int u=0;u<i;u++){
                k/=10;
            }

            while(a*b>n && z<15){
                a+=k;
                b-=k;
                z++;

            }
            a-=k;
            b+=k;
        }
        cout << setprecision(12);
        if (n==0){
            cout << "Y " <<  "0.0000000000" << " " << "0.0000000000" << endl;
            continue;
        }
        if (a<0.0 || b<0.0){
            cout << "N" << endl;
            continue;
        }
        
        cout << "Y " << a << " " << b << endl;

    }




    return 0;
}