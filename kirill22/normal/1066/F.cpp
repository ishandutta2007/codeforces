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
ll D(pair<int,int> x,pair<int,int> y){
    return abs(x.second-y.second)+abs(x.first-y.first);
}
const long long  INF=1e9*1e9;
int main() {
    Routine();
    int n;
    cin >> n;
    map<int,vector<pii>> a;

    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        a[max(x,y)].push_back({x,-1*y});
    }
    a[0].push_back({0,0});
    for(auto &&j:a){
        sort(j.second.begin(),j.second.end());

    }
    long long m[a.size()+1][2];
    for(int i=0;i<a.size()+1;i++){
        for(int u=0;u<2;u++){
            m[i][u]=INF;
        }

    }
    m[0][0]=0;
    m[0][1]=0;
    int L=0,pred=0;

    for(auto &&j:a){
        L++;
        pair<int,int>cu=j.second[0];
        pair<int,int> cu1=j.second[j.second.size()-1];
        pair<int,int> pr=a[pred][0];
        pair<int,int> pr1=a[pred][a[pred].size()-1];

        m[L][0]=min(m[L][0],m[L-1][0]+D(pr,cu1)+D(cu,cu1));
        m[L][0]=min(m[L][0],m[L-1][1]+D(pr1,cu1)+D(cu,cu1));
        m[L][1]=min(m[L][1],m[L-1][0]+D(pr,cu)+D(cu,cu1));
        m[L][1]=min(m[L][1],m[L-1][1]+D(pr1,cu)+D(cu,cu1));
        pred=j.first;


    }
    cout << min(m[L][0], m[L][1]);







    return 0;
}