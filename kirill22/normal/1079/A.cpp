#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
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
const long long MOD=1e10+7;

int main() {
    Routine();
    int n,k;
    cin >> n >> k;
    int a[101]={0};
    for(int i=1;i<=100;i++){
        a[i]=0;
    }
    for(int i=0;i<n;i++){
        int u;
        cin >> u;
        a[u]++;
    }
    int co=0,ans=0;
    for(int i=1;i<=100;i++){
        co=max(co,a[i]);
        if (a[i]!=0){
            ans++;
        }
    }
    if (co%k==0){
        cout << co*ans-n;
    }
    else{
        cout << ((co+k-co%k)/k)*ans*k-n;
    }




    return 0;
}