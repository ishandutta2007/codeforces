 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

#define pb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define INF 1000000
#define EPS 1e-4
#define MAXN int(1e6)

//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

inline void Routine(){
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

template<class T, class U>
istream &operator >> (istream &in, pair<T, U> &p) {
    in >> p.fi >> p.se;
    return in;
}

template<class T, class U>
ostream &operator << (ostream &out, const pair<T, U> &p) {
    out << p.fi << ' ' << p.se;
    return out;
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
    ll n,k,x,co=0,y;
    string s,s1="";
    cin >> n >>k;
    int a[n+k];
    for(int i=0;i<n+k;i++){
        cin >> a[i];
    }
    int m[n+k];
    vector<pii> ta;
    for(int i=0;i<n+k;i++){
        cin >> m[i];
        if (m[i]==1){
                co++;
            ta.push_back(make_pair(a[i],i));
        }
    }
    int ans[co]={0};

    for(int i=0;i<ta.size()-1;i++){
        for(int u=ta[i].second+1;u<ta[i+1].second;u++){
            if (abs(ta[i].first-a[u])<=ta[i+1].first-a[u]){
                ans[i]++;
            }
            else{
                ans[i+1]++;
            }
        }
    }
    int ii=0;

    while(m[ii]==0){
        ans[0]++;
        ii++;
    }
    ii=n+k-1;

    while(m[ii]==0){

        ans[co-1]++;
        ii--;
    }
    for(int i=0;i<co;i++){
        cout << ans[i] << " ";
    }


    return 0;
}