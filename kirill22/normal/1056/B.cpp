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
    cin >> n >> k;
    ll cnt[1005]={0};
    for(ll i=1;i<=n;i++){
        if (i==k+1){
            break;
        }
        cnt[(i*i)%k]++;
        if ((i*i)%k==0){
            cnt[k]++;
        }
    }
    ll p=n/k;
    for(int i=0;i<=k;i++){
        cnt[i]*=p;
    }
    ll oc=n%k;
    for(int i=1;i<=oc;i++){
        cnt[(i*i)%k]++;
        if ((i*i)%k==0){
            cnt[k]++;
        }
    }
    for(int i=0;i<k;i++){
        ans+=cnt[i]*cnt[k-i];
    }
    cout << ans;




    return 0;
}