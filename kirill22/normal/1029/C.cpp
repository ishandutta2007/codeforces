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
    ll n,ans=0,L,R,maxl,maxl1,maxr,maxr1,ansi=0,ansu=0;

    cin >> n ;
    int a[n][2];
    cin >> a[0][0] >> a[0][1];
    maxl=a[0][0];
    maxr=a[0][1];
    maxr1=a[0][0]+a[0][1];
    maxl1=a[0][0]+a[0][1];
    for(int i=1;i<n;i++){
            cin >> a[i][0] >> a[i][1];
            if (a[i][0]>maxl){
                maxl=a[i][0];
                ansi=i;
            }
            if (a[i][1]<maxr){
                maxr=a[i][1];
                ansu=i;
            }
            if (a[i][0]==maxl){
                if (a[i][1]<a[ansi][1]){
                    ansi=i;
                }
            }
            if (a[i][1]==maxr){
                if (a[i][0]>a[ansu][0]){
                    ansu=i;
                }
            }
    }
    ll r[2];
    r[0]=ansi;
    r[1]=ansu;
    for(int m=0;m<2;m++){
        ll y=r[m];

        if (y==0){
            L=a[1][0];
            R=a[1][1];
        }
        else{
            L=a[0][0];
            R=a[0][1];
        }
        for(int i=0;i<n;i++){
            if (i==y){
                continue;
            }
            if (a[i][0]>L){
                L=a[i][0];
            }
            if (a[i][1]<R){
                R=a[i][1];
            }
        }

        if (R-L>ans){
            ans=R-L;
        }
        if (ans>=a[y][1]-a[y][0]){
            cout << ans;
            return 0;
        }

    }
    cout << ans;

    return 0;



    return 0;
}