#include <bits/stdc++.h>

using namespace std;

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
    modulo(int val_){val=val_;}
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
        fact_vector.push_back(1);
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
#define int long long
#define pb push_back

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int d;
    cin>>d;
    vector<int> pr;
    for (int i=2; i*i<=d; i++)
        if (d%i==0)
    {
        pr.pb(i);
        while (d%i==0)
            d/=i;
    }
    if (d>1) pr.pb(d);
    int q;
    cin>>q;
    for (int ii=0; ii<q; ii++)
    {
        int u, v;
        cin>>u>>v;
        int g=__gcd(u, v);
        u/=g;
        v/=g;
        vector<int> cntu, cntv;
        for (int i:pr)
        {
            if (u%i==0)
            {
                int c=0;
                while (u%i==0)
                    c++, u/=i;
                cntu.pb(c);

            }
            if (i*i>u)
                break;
        }
        if (u>1) cntu.pb(1);
        for (int i:pr)
            {
                if (v%i==0)
            {
                int c=0;
                while (v%i==0)
                    c++, v/=i;
                cntv.pb(c);
            }
        if (i*i>v)
            break;
    }
       if (v>1) cntv.pb(1);
        cout<<multicnk(accumulate(cntu.begin(), cntu.end(), 0), cntu)*multicnk(cntv)<<"\n";
    }
    return 0;
}