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
const int mxN = 3e5+1, oo = 1e9;
bitset<mxN> have;
const int store=3e5 + 1;
bitset<store> sieve={};
int factor[store] = {};
void makesieve() {
    for(int i = 2; i < store;++i) {
        if(!sieve[i]) {
            for(int j = i;j<store;j+=i) {
                if(!sieve[j]) {
                    factor[j] = i;
                    sieve[j] = true;
                }
            }
        }
    }
}
int cnt[mxN];
vi fs;
int pie=0;
void rec(int i, int j=1, int num=0) {
    if(i==-1) {
        int before = cnt[j]++;
        if(num%2==1) pie-=before;
        else pie+=before;
        return;
    }
    int p = fs[i];
    rec(i-1,j,num);
    rec(i-1,j*p,num+1);
}
int now=0,n;
vi b;
void rec2(int i, int j, int g=0) {
    if(g==1) {
        cout << now << '\n';
        exit(0);
    }
    if(j==0) return;
    for(int k=i;k<n;++k) {
        rec2(k+1,j-1,gcd(g,b[k]));
    }
}
int main() {
    makesieve();
    cin >> n;
    for(int i=0;i<n;++i) {
        int a,c=1; cin >> a;
        while(a!=1) {
            int f = factor[a];
            while(a%f==0) a/=f;
            c*=f;
        }
        // make canonical
        have[c]=true;
    }
    for(int i=0;i<mxN;++i) {
        if(have[i]) {
            b.push_back(i);
            for(int j=i*2;j<mxN;j+=i) 
                have[j]=false; // delete multiples, they are unneccesary
        }
    }
    n = b.size();
    int g=0;
    for(auto i : b) g = gcd(i,g);
    if(g!=1) {
        cout << "-1\n";
        exit(0);
    } 
    if(b[0]==1) {
        cout << "1\n";
        exit(0);
    }
    // check pairs
    for(int i : b) {
        fs.clear();
        while(i!=1) {
            int f = factor[i];
            while(i%f==0) i/=f;
            fs.push_back(f);
        }
        pie=0;
        rec(fs.size()-1);
        // check if gcd == 1 pair with current number exists
        if(pie!=0) {
            cout << "2\n";
            exit(0);
        }
    }
    // b's size should be small and i<=7 will always work, bruteforce
    // Something^7/(big constant)
    for(int i=3;i<=n;++i) {
        now=i;
        rec2(0,i);
    }

}