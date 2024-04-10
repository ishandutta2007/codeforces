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
vector<pair<int,int>> kol;
vector<int> a;
int used[200001];
int f(int m,int k){
    int ans=0;
    for(int i=0;i<kol.size();i++){
        ans+=(kol[i].first)/m;
    }

    return ans>=k;
}

int main() {
    Routine();
    ll n,k;
    cin >> n >> k;
    a.resize(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
        used[a[i]]++;
    }

    for(ll i=0;i<200001;i++){
        if (used[i]!=0){
            kol.push_back({used[i],i});
        }

    }
    ll L=0,R=n;
    while(R-L>1){

        ll m=(R+L)/2;
        if (f(m,k)){
            L=m;
        }
        else{
            R=m;
        }
    }
    if (R==1){
            for(int i=0;i<k;i++){
                cout << a[i] << " ";
                return 0;
            }

        }

    ll o=0;
    for(ll i=0;i<kol.size();i++){
        ll a1=kol[i].first/L;
        for(ll u=0;u<a1;u++){
                if (o==k){
                    return 0;
                }
            cout << kol[i].second << " ";
            o++;
        }
    }







    return 0;
}