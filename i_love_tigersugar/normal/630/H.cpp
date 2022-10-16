/*
This code includes arithmetic operators of big numbers
Notes
	Numbers use base 1e4 (const int base)
	MAXD is the maximum number of digits
*/
#include<bits/stdc++.h>
#define MAX   111
#define MAXD   55
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define MASK(i) (1<<(i))
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
const int base=(int)1e4;
struct Bignum {
    int nd,d[MAXD];
    Bignum() {
        nd=0;
        memset(d,0,sizeof d);
    }
    Bignum(long long x) {
        nd=0;
        memset(d,0,sizeof d);
        if (x==0) nd++;
        while (x>0) {
            d[nd++]=x%base;
            x/=base;
        }
    }
    Bignum(const Bignum &x) {
        memset(d,0,sizeof d);
        nd=x.nd;
        REP(i,nd) d[i]=x.d[i];
    }
    void operator += (const Bignum &x) {
        int ND=nd;
        nd=0;
        int c=0;
        REP(i,max(ND,x.nd)) {
            int a=i<ND?d[i]:0;
            int b=i<x.nd?x.d[i]:0;
            if (a+b+c>=base) {
                d[nd++]=a+b+c-base;
                c=1;
            } else {
                d[nd++]=a+b+c;
                c=0;
            }
            assert(nd<MAXD);
        }
        while (c>0) {
            d[nd++]=c%base;
            c/=base;
            assert(nd<MAXD);
        }
        while (nd>1 && d[nd-1]==0) nd--;
    }
    Bignum operator + (const Bignum &x) const {
        Bignum c=*this;
        c+=x;
        return (c);
    }
    void operator -= (const Bignum &x) {
        assert(*this>=x);
        int ND=nd;
        nd=0;
        int c=0;
        REP(i,ND) {
            int a=d[i];
            int b=i<x.nd?x.d[i]:0;
            if (a>=b+c) {
                d[nd++]=a-b-c;
                c=0;
            } else {
                d[nd++]=a-b-c+base;
                c=1;
            }
        }
        while (nd>1 && d[nd-1]==0) nd--;
    }
    Bignum operator * (int k) const {
        Bignum res;
        int c=0;
        REP(i,nd) {
            res.d[res.nd++]=(d[i]*k+c)%base;
            c=(d[i]*k+c)/base;
        }
        while (c>0) {
            res.d[res.nd++]=c%base;
            c/=base;
        }
        while (res.nd>1 && res.d[res.nd-1]==0) res.nd--;
        return (res);
    }
    Bignum operator / (int k) const {
        Bignum res;
        int rem=0;
        FORD(i,nd-1,0) {
            res.d[res.nd++]=(rem*base+d[i])/k;
            rem=(rem*base+d[i])%k;
        }
        reverse(res.d,res.d+res.nd);
        while (res.nd>1 && res.d[res.nd-1]==0) res.nd--;
        return (res);
    }
    int operator % (int k) const {
        int res=0;
        FORD(i,nd-1,0) res=(res*base+d[i])%k;
        return (res);
    }
    int cmp(const Bignum &x) const {
        if (nd!=x.nd) return ((nd>x.nd)-(nd<x.nd));
        FORD(i,nd-1,0) if (d[i]!=x.d[i]) return ((d[i]>x.d[i])-(d[i]<x.d[i]));
        return (0);
    }
    void print(void) const {
        printf("%d",d[nd-1]);
        FORD(i,nd-2,0) printf("%04d",d[i]); printf("\n");
    }
    #define DEF_OPER(x) bool operator x (const Bignum &a) const { return (cmp(a) x 0); }
    DEF_OPER(<) DEF_OPER(>) DEF_OPER(<=) DEF_OPER(>=) DEF_OPER(==) DEF_OPER(!=)
    #undef DEF_OPER
};
long long comb(int k,int n) {
    if (k>n) return (0);
    long long res=1;
    REP(i,k) res=res*(n-i);
    REP(i,k) res=res/(i+1);
    return (res);
}
int main(void) {
    int n;
    cin>>n;
    cout<<comb(5,n)*comb(5,n)*120<<endl;
    return 0;
}