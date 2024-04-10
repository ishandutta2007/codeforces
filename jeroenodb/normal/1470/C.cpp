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
const int mxN = 1e5+1, oo = 1e9;
vi simulate(vi a) {
    int n = a.size();
    vi res(n);
    for(int i=1;i<n; ++i) {
        res[(i+1)%n]+=(a[i]+1)/2;
        res[i-1] += a[i]/2;
    }
    res[1]+=a[0];
    return res;
}
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
int t=0,n;
int query(int i) {
    i%=n;
    cout << "? " << i+1 << endl;
    cin >> i;
    t++;
    return i;
}
void answer(int i) {
    i%=n;
    cout << "! " << i+1 << endl;
}
int main() {
    // vi a(10,2);
    // for(int i=0;i<20;++i) {
    //     vi b = a;
    //     rotate(b.begin(),b.begin()+5,b.end());
    //     cout << b << '\n';
    //     a = simulate(a);
    // }
    int k; cin >> n >> k;
    int i=-1;
    do {
        i=rnd(0,n-1);
    } while(query(i)>=k);
    int j=-1;
    do {
        j=rnd(0,n-1);
    } while(query(j)<=k);
    if(j<i) j+=n;
    while(i<j) {
        int mid = (i+j)/2;
        int val = query(mid);
        if(val==k) {
            answer(mid);
            exit(0);
        } else if(val>k) {
            j=mid-1;
        } else i=mid+1;
    }
    answer(i);

}