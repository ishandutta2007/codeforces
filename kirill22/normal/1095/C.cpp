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
ll used[42]={0};
int main() {

    ll b,c,x,z,x1,y1,co=0,n,m,k;

    cin >> n >> k;
    vector<int> a;
    ll n1=n;

    if (  k>n){
        cout << "NO";
        return 0;
    }


    ll ans=0;
    ll y=0;
    while(n1!=0){
            y=0;
        ll h=1;
        while(h<=n1){
            h*=2;y++;
        }
        n1-=h/2;
        used[y-1]++;
        ans++;
    }
    while(ans<k){
            bool flag=true;
        for(ll  i=1;i<39;i++){
        if (used[i]>0){
            used[i]--;
            used[i-1]+=2;
            flag=false;
            ans++;
            break;
            ans++;
        }
    }
    if (flag){
        break;
    }
    }


    ll t=2;
    if (ans!=k){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for(ll  i=0;i<39;i++){
        for( ll u=0;u<used[i];u++){
            cout << (1<<i) << " ";
        }
    }







    return 0;
}