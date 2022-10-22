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
 map<int,int> a;
int main() {
    int n;

    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        a[k]++;
    }
    vector<int> kol;
    for(auto o : a){
        kol.push_back(o.second);
    }
    int ans=0;
    sort(kol.begin(),kol.end());
    for(int i=1;i<=kol[kol.size()-1];i++){
        int maxi=i,ansi=i,ii=kol.size()-1;
        while(maxi%2==0 && ii>0){
            maxi/=2;
            ii--;
            if (maxi>kol[ii]){
                break;
            }
            ansi+=maxi;
        }
        ans=max(ans,ansi);
    }
    cout << ans;



    return 0;
}