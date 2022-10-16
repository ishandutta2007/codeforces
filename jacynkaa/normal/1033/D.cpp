#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10), cin.tie(0), cout.tie(0);
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(c) (c).begin(), (c).end()
#define sz(X) (int)((X).size())
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
// mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());uniform_int_distribution<int> distr(0, 1e9);auto my_rand = bind(distr, gen); // my_rand() zwraca teraz liczbe z przedzialu [a, b]

ostream &operator<<(ostream &out, string str) {
   for (char c : str)
      out << c;
   return out;
}
template <class L, class R> ostream &operator<<(ostream &out, pair<L, R> p) { return out << "(" << p.st << ", " << p.nd << ")"; }
template <class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
   out << '{';
   for (auto it = a.begin(); it != a.end(); it = next(it))
      out << (it != a.begin() ? ", " : "") << *it;
   return out << '}';
}
void dump() { cerr << "\n"; }
template <class T, class... Ts> void dump(T a, Ts... x) {
   cerr << a << ", ";
   dump(x...);
}
#define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)

 
typedef __int128_t lll;
#define int long long
 
lll mod_pow(lll a, lll b, lll mod) {
   lll res = 1;
   for (; b > 0; a = (a * a) % mod, b = b / 2)
      if (b % 2 == 1)
         res = (res * a) % mod;
   return res;
}
 
vector<lll> tab = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
 
bool isPrime(lll p) {
 
   if (p == 1)
      return false;
 
   int r = __builtin_ctzll(p - 1);
   auto d = (p - 1) >> r;
 
   for (auto a : tab) {
 
      if (a == p)
         return true;
      if (p % a == 0)
         return false;
 
      lll t = mod_pow(a, d, p);
 
      if (t == (p - 1) || t == 1)
         continue;
 
      bool prime = false;
      rep(i, r) {
         t = (t * t) % p;
         if (t == (p - 1))
            prime = true;
      }
      if (!prime)
         return false;
   }
   return true;
}
 
inline ll pollard(ll n) // znajduje nietrywialny dzielnik n
{
   for (int a : tab)
      if (n % a == 0)
         return a;
 
   for (int c = 1;; c++) {
 
      auto g = [n, c](lll x) { return (x * x + c) % n; };
 
      ll x = tab[rand() % sz(tab)];
      ll y = g(x);
 
      ll p = gcd(abs(x - y), n);
 
      int r = 0;
      int limit = 20 * pow(n, 0.25);
 
      while (p == 1 && r++ < limit) {
         x = g(x), y = g(g(y));
         p = gcd(abs(x - y), n);
      }
      if (p != 1 && p != n)
         return p;
   }
}
 
vector<ll> factor(ll n) {
   if (n == 1)
      return {};
   if (isPrime(n))
      return {n};
 
   ll x = pollard(n);
   auto A = factor(x);
   auto B = factor(n / x);
 
   A.insert(A.end(), all(B));
   return A;
}

#define int long long

int32_t main(){
    map<int,int>M;
    long long wynik=1;
    int n;
    cin>>n;
    
    vector<ll>X(n);
    
    map<ll,ll>P;
    map<ll,ll> N;
    
    rep(i,n){
        cin>>X[i];
        for(int k=2;k<=6;k++){
            ll r=pow(X[i],1.0/k)+0.5;
            ll w=1;
            rep(i,k) w*=r;
            if(w==X[i]) P[r]=0;
        }
    }
    
    rep(i,n) rep(j,n) {
        auto r=gcd(X[i],X[j]);
        if(isPrime(r)) P[r]=0;
    }
    
    rep(i,n) {for(auto& [p,s]:P){
        while(X[i]%p==0){
            X[i]/=p;
            s++;
        }
    }
            if(isPrime(X[i])) P[X[i]]++;
        else N[X[i]]++;
    }
    
    //cout<<P<<endl;
    //cout<<N<<endl;
    
    const ll MOD=998244353;
    for(auto [a,b]: P) wynik=(wynik*++b)%MOD;
    for(auto [a,b]:N) if(a!=1) wynik=(wynik*(b+1)*(b+1))%MOD;
    
    cout<<wynik<<endl;
}