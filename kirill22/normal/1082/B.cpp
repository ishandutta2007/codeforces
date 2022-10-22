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

    int n,m,k,L,R,ans=0,co=0,ii=0,i;
    cin >> n;
    string s;
    cin >> s;
    vector<pii> a;
    for(i=0;i<n;i++){
        if (s[i]=='G'){
            co++;
            if (i==n-1){
                a.push_back({ii,n});
            }
        }
        else{
                if (ii!=i){

            a.push_back({ii,i});
                }
            ii=i+1;


        }
        ans=max(ans,i-ii+1);

    }


    if (ii!=i){

            a.push_back({ii,i});
        }
        if (co==0){
            cout << 0;
            return 0;
        }
        for(int i=0;i<a.size()-1;i++){
            if (a[i].second+1==a[i+1].first && (a[i].second-a[i].first+a[i+1].second-a[i+1].first)!=co){
                ans=max(ans,(a[i].second-a[i].first+a[i+1].second-a[i+1].first)+1);
            }
            else if(a[i].second+1==a[i+1].first){
                ans=max(ans,(a[i].second-a[i].first+a[i+1].second-a[i+1].first));
            }
        }
        for(int i=0;i<a.size();i++){
            if ((a[i].second-a[i].first)!=co){
                ans=max(ans,(a[i].second-a[i].first)+1);
            }
        }


    cout << ans;





    return 0;
}