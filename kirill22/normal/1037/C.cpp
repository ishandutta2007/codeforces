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
    ll n, k,ans=0,b=1,m=0,l;
    string s,s1;
    cin >> n ;
    cin >> s >> s1;
    if (s==s1){
        cout << 0;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(s[i]==s1[i]){
            m++;
        }
    }
    ll i=0;
    while(i<n-1){
        if (s[i]==s1[i]){
            i+=1;
            continue;

        }
        else if(s[i+1]==s1[i] && s[i+1]==s1[i+1]){
            ans+=1;
            i+=2;
            continue;
        }
        else if(s[i+1]==s1[i]){
            char c=s[i+1];
            s[i+1]=s[i];
            s[i]=c;
            ans+=1;
            i+=1;
        }
        else{
            ans+=1;
            i+=1;
        }
    }
    if (s[n-1]!=s1[n-1]){
        ans++;
    }
    cout << min(ans,n-m);






    return 0;
}