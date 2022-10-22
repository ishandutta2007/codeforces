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
    ll n, k=0,k1=0,ko=0,ans=0,ko1,z=0,a0=0,a1=0,a2=0,a3=0;
    cin >> n;
    string s,s1;
    cin >> s;
    cin >> s1;
    for(ll i=0;i<n;i++){
    	if (s[i]=='0' && s1[i]=='0'){
	
    		a1++;
    	}

    	else if (s[i]=='1' && s1[i]=='0' ){
    		
    		a2++;
    	}
    	else if (s[i]=='1' && s1[i]=='1' ){
    		
    		a3++;
    	}
    	else if (s[i]=='0' && s1[i]=='1' ){
    		
    		a0++;
    	}
    
    }
    for(ll i=0;i<n;i++){
    	if (s1[i]=='0'){
    		if (s[i]=='1'){
    			ans+=a0*2+a1;
    		}
    		if (s[i]=='0'){
    			ans+=a3*2+a2;
    		}
    	}
    	
    }
    cout << ans/2 ;
    return 0;
}