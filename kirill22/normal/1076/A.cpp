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
    string s;
    cin  >> s;

    char c=char(s[0]);
    int o=-1;
    for(int i=0;i<n-1;i++){
        if (s[i]>s[i+1]){
            o=i;
            break;
        }
    }

    if (o==-1){
        for(int i=0;i<n-1;i++){
        cout << s[i];
    }
    }
    else{
        for(int i=0;i<n;i++){
        if (i!=o){
            cout << s[i];
        }
    }
    }



    return 0;
}