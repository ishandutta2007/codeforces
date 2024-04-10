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
ll used[42];
int main() {

    ll b,c,x,y,z,x1,y1,co=0,n,m,k;

    cin >> n ;
    vector<int> a1;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        cin >> x >> y;

        a.push_back({x,y});
        if (x==1 || y==1){
            a1.push_back(i+1);
        }
    }

    x=a1[0];
    y=a1[1];
    vector<int> ans;
    ans.push_back(1);
    if (y==a[x-1].second || y==a[x-1].first){
        if (a[y-1].first==1){
        cout << a[y-1].second << " ";
        ans.push_back(a[y-1].second);
        }
        else{
            cout << a[y-1].first << " ";
        ans.push_back(a[y-1].first);
        }
    }

    else{
        if (a[x-1].first==1){
        cout << a[x-1].second << " ";
        ans.push_back(a[x-1].second);
        }
        else{
            cout << a[x-1].first << " ";
        ans.push_back(a[x-1].first);
        }
    }
    for(int i=2;i<=n;i++){
        if (a[ans[i-2]-1].first==ans[i-1]){
            cout << a[ans[i-2]-1].second << " ";
            ans.push_back(a[ans[i-2]-1].second);
        }
        else{
            cout << a[ans[i-2]-1].first << " ";
            ans.push_back(a[ans[i-2]-1].first);
        }
    }






    return 0;
}