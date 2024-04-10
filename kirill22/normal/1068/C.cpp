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
    int b,c,d,n,ans=0,m;
    string s,s1;

    cin >> n >> m;

    int mas[n+100]={0};
    int an[n+1][10020]={0};
    vector<pii> hashi;
    for(int i=0;i<m;i++){
        cin >> b >> c;

        hashi.push_back(make_pair(b,c));
        mas[c]++;
        mas[b]++;

    }
    for(int k=0;k<m;k++){
        int i=hashi[k].first;
        int u=hashi[k].second;
        ans++;

        an[i][ans]=1;
        an[u][ans]=1;


    }

    for(int i=1;i<=n;i++){


        if (mas[i]==0){
            cout << 1 << endl << i << " " << i+1000001 << endl;
        }
        else{
            cout << mas[i]<< endl;
            for(int u=1;u<=ans;u++){


            if (an[i][u]==1){
                cout << i << " " << u<<endl;

            }
        }
        }

    }













    return 0;
}