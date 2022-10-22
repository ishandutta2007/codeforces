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
    ll b,c,d,n,ans=0;
    string s,s1;

    cin >> n ;
    int a[n-1];
    int m[n-1];
    int an[n];
    for(int i=0;i<n-1;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        cin >> m[i];
        if (m[i]>a[i]){
            cout <<"NO";
            return 0;
        }
    }
    an[0]=m[0];
    for(int i=1;i<n-1;i++){
        an[i]=m[i-1]|m[i];
    }
    an[n-1]=m[n-2];

    for(int i=0;i<n-1;i++){
        if ( ((an[i])|(an[i+1]))!=a[i]){
            if (i<n-2){
                ll k=a[i]^a[i+1];
                ll ki=k&a[i];
                an[i]=an[i]|ki;
                an[i+2]=an[i+2]|(k&a[i+1]);
                if ( ((an[i])|(an[i+1]))!=a[i]){
                    an[i+1]=(a[i]&(a[i]^an[i]))|an[i+1];
                }
            }
            else{
                an[i+1]=(a[i]&(a[i]^an[i]))|an[i+1];
            }

        }
    }
    for(int i=0;i<n-1;i++){
        if ( ((an[i])|(an[i+1]))!=a[i]){
            swap(an[0],an[1]);break;

        }
        if ( ((an[i])&(an[i+1]))!=m[i]){
            swap(an[0],an[1]);break;
        }
    }
    for(int i=0;i<n-1;i++){
        if ( ((an[i])|(an[i+1]))!=a[i]){
            cout << "NO";return 0;

        }
        if ( ((an[i])&(an[i+1]))!=m[i]){
            cout << "NO";return 0;

        }
    }
    cout << "YES" << endl;
    for(int i=0;i<n;i++){
        cout << an[i] << " ";
    }










    return 0;
}