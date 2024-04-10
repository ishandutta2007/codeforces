#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int store=1e5;
bitset<store+1> S={};
bitset<store+1> sieve={};
vi small, big;
void makesieve() {
    for(int i = 2; i <= store;++i) {
        if(!sieve[i]) {
            if((ll)i*i<=store) small.push_back(i);
            else big.push_back(i);
            for(int j = i*2;j<=store;j+=i) {
                sieve[j] = true;
            }
        }
    }
}
int n;
void query2(ll a) {
    cout << "B " << a << endl;
    for(ll j=a;j<=n;j+=a) {
        S[j]=false;
    }
    cin >> a;
}
bool query1(ll a) {
    cout << "A " << a << endl;
    int res; cin >> res;
    // if(a==1) return S.count()!=res;
    int expect=0;
    for(ll j=a;j<=n;j+=a) {
        expect+=S[j];
    }
    return res-expect;
}
const int B=100;
int main() {
    makesieve();
    cin >> n;
    for(int i=1;i<=n;++i) S[i]=true;
    ll x=1;
    while(!small.empty() and small.back()>n) small.pop_back();
    while(!big.empty() and big.back()>n) big.pop_back();
    int k = big.size();
    for(int l=0;l<k;l+=100) {
        int r=min(k-1,l+99);
        for(int i=l;i<=r;++i) {
            query2(big[i]);
        }
        if(query1(1)) {
            bool found=false;
            for(int i=l;i<=r;++i) {
                if(query1(big[i])) {
                    found=true;
                    x*=big[i];
                    break;
                }
            }
            assert(found);
            break;
        }
    }
    for(auto i : small) {
        query2(i);
        ll pw=i;
        while(pw<=n and query1(pw)) {
            x*=i,pw*=i;
            
        }
    }
    cout << "C " << x << endl;
}