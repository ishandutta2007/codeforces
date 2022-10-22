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
    ll n,k=0,k1=0,ko=2,ans=0,ko1;
    
    cin >> k;
    ans=(k)/2+k%2+2;
    for(ll i=3;i<=k;i++){
    	ko1=k/i+i;
    	if (k%i!=0){
    		ko1++;
    	}
    	if (ko1<ans){
    		ans=ko1;
    		ko=i;
    	}
    	
    }
    vector <int> pos;
    for(ll i=k;i%ko!=0;i--){
    	pos.push_back(i);
    }
    for(int i=0;i<pos.size();i++){
    	cout << pos[pos.size()-i-1] << " ";
    }
    bool flag=true;
    for(ll i=k-k%ko-ko+1;i>0;i-=ko){
    	cout << i << " ";
    	for(ll u=i+1;u%ko!=1;u++){
    		cout << u << " ";
    	}
    }
    return 0;
}