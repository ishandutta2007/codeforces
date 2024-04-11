#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
const int nmax=5e5+100;

//int mod=1e9+7;
int mod=998244353;
int pow(int base, int n)
{
    long long a=base;
    long long res=1;
    while (n){
        if (n&1) res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}

struct modulo{
    modulo(){val=0;}
//    modulo(int val_){val=val_;}
    modulo(size_t val_){val=val_;}
    modulo(long long val_){val=val_%mod;}
    int val;
};
modulo inv(modulo a){ return pow(a.val, mod-2); }
ostream& operator<<(ostream& stream, const modulo& x){ stream<<x.val; return stream; }
istream& operator>>(istream& stream, modulo& x){ long long val; stream>>val; x.val=val%mod; return stream; }
modulo operator+(const modulo& x, const modulo& y) { return x.val+y.val<mod? x.val+y.val: x.val+y.val-mod; }
modulo operator-(const modulo& x, const modulo& y) { return x.val>=y.val?    x.val-y.val: x.val-y.val+mod; }
modulo operator*(const modulo& x, const modulo& y) { return ((long long)(x.val)*(y.val)); }
modulo operator/(const modulo& x, const modulo& y) { return x*inv(y); }
modulo operator+=(modulo& x, const modulo& y) { return x=x+y; }
modulo operator-=(modulo& x, const modulo& y) { return x=x-y; }
modulo operator*=(modulo& x, const modulo& y) { return x=x*y; }
modulo operator/=(modulo& x, const modulo& y) { return x=x/y; }
vector<modulo> fact_vector;
modulo fact(modulo n){
    if (fact_vector.size()==0)
    {
        cerr<<"Modulo is "<<mod<<". Check that it is correct. (this output shouldn't be commented)\n";
        fact_vector.push_back(1ll);
    }
    while (fact_vector.size()<=size_t(n.val)) fact_vector.push_back(
            fact_vector.size()*fact_vector[fact_vector.size()-1]);
    return fact_vector[n.val];
}
modulo cnk(const modulo& n, const modulo& k){ return fact(n)/fact(k)/fact(n-k); }
modulo ank(const modulo& n, const modulo& k){ return fact(n)/fact(n-k); }
template<typename T>
modulo multicnk(modulo s, const vector<T>& v){
    modulo ans(fact(s)); for (const T& m:v) ans/=fact(m), s-=m;
    return ans/fact(s);
}
template<typename T>
modulo multicnk(const vector<T>& v){
    modulo s=0; for (const T& m:v) s+=m;
    modulo ans(fact(s)); for (const T& m:v) ans/=fact(m);
    return ans;
}

int n, k;
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    if (k==0) cout<<fact(n), exit(0);
    if (k>=n) cout<<0, exit(0);
    modulo ans=0ll;
    k=n-k;
    for (int i=0; i<=k; i++)
        if (i%2==0)
            ans+=cnk(k, i)*pow(k-i, n);
        else
            ans-=cnk(k, i)*pow(k-i, n);
//    cout<<ans<<"\n";
    cout<<2ll*ans*cnk(n, k);
}