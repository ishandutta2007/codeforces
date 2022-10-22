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
    cin >> n >> k;
    vector<pii> a;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        a.push_back({x,y});
    }

    sort(a.begin(),a.end());
    vector<pii> o;
    i=n-1;

    vector<int> a1[k+1];


    while(i>=0){
        int now=a[i].first,co=1,sum=a[i].second;
        i--;
        if (sum<0){
            co--;
        }
        else{
            a1[now].push_back(sum);
        }
        while(a[i].first==now && i>-1){
            sum+=a[i].second;
            i--;
            if (sum>=0){
                co++;
                a1[now].push_back(sum);
            }
        }
        if (co!=0){
            o.push_back({co,now});
        }

    }
    if ((o.size()==0)){
        cout << 0;
        return 0;
    }

    sort(o.begin(),o.end());

    for(int i=1;i<=o[o.size()-1].first;i++){
        int ansi=0;
        for(int u=o.size()-1;u>-1;u--){
            if (o[u].first<i){
                break;
            }
            else{
                ansi+=a1[o[u].second][i-1];
            }
        }
        ans=max(ans,ansi);
    }
    cout << max(ans,0);







    return 0;
}