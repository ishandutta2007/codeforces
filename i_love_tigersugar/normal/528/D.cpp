#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define STORE_AT(level,setID,pos) ((setID)+(level)*(pos))
#define fi   first
#define se   second
using namespace std;
const double PI=acos(-1.0);
const double eps=0.3;
struct Complex {
    double real,imag;
    Complex() {
        real=imag=0;
    }
    Complex(double a,double b,bool mode) {
        if (mode) {
            real=a;imag=b;
        } else {
            real=a*cos(b);
            imag=a*sin(b);
        }
    }
    Complex operator + (const Complex &a) const {
        return (Complex(real+a.real,imag+a.imag,true));
    }
    Complex operator - (const Complex &a) const {
        return (Complex(real-a.real,imag-a.imag,true));
    }
    Complex operator * (const Complex &a) const {
        return (Complex(real*a.real-imag*a.imag,real*a.imag+a.real*imag,true));
    }
    int round(void) const {
        return (int(real+eps));
    }
};
void DFT(vector<Complex> &a,bool inverse) {
    int n=a.size();
    if (n==1) return;
    Complex root=inverse?Complex(1,-2*PI/n,false):Complex(1,2*PI/n,false);
    vector<Complex> w(n);
    REP(i,n) w[i]=i==0?Complex(1,0,true):w[i-1]*root;
    vector<Complex> b(n);
    bool mode=true;
    for (int level=n/2;level>=1;level/=2) {
        vector<Complex> &cur=mode?b:a;
        vector<Complex> &prev=mode?a:b;
        mode^=1;
        REP(setID,level) REP(pos,n/level/2) {
            cur[STORE_AT(level,setID,pos)]=prev[STORE_AT(2*level,setID,pos)]+w[pos*level]*prev[STORE_AT(2*level,setID+level,pos)];
            cur[STORE_AT(level,setID,pos+n/level/2)]=prev[STORE_AT(2*level,setID,pos)]-w[pos*level]*prev[STORE_AT(2*level,setID+level,pos)];
        }
    }
    if (!mode) a=b;
    if (inverse) REP(i,n) a[i].real/=n;
}
void multiply(const vector<int> &a,const vector<int> &b,vector<int> &c) {
    int n=a.size()+b.size()-1;
    while (__builtin_popcount(n)!=1) n++;
    vector<Complex> va,vb;
    FORE(it,a) va.push_back(Complex(*it,0,true));
    FORE(it,b) vb.push_back(Complex(*it,0,true));
    while ((int)va.size()<n) va.push_back(Complex());
    while ((int)vb.size()<n) vb.push_back(Complex());
    DFT(va,false);
    DFT(vb,false);
    vector<Complex> vc;
    REP(i,n) vc.push_back(va[i]*vb[i]);
    DFT(vc,true);
    c.clear();
    FORE(it,vc) c.push_back(it->round());
}
const string ch="ACGT";
vector<int> occurPos[4];
string s,t;
int ls,lt,lim;
void init(void) {
    cin>>ls>>lt>>lim>>s>>t;
}
void maskString(const string &s,char c,int lim,vector<int> &res) {
    vector<pair<int,int> > seg;
    REP(i,s.size()) if (s[i]==c) seg.push_back(make_pair(max(0,i-lim),min((int)s.size()-1,i+lim)));
    sort(ALL(seg));
    int id=0;
    int maxR=-1;
    res.clear();
    REP(i,s.size()) {
        while (id<(int)seg.size() && seg[id].fi<=i) {
            maxR=max(maxR,seg[id].se);
            id++;
        }
        res.push_back(maxR>=i);
    }
}
void getOccurPos(char c,vector<int> &res) {
    vector<int> maskS,maskT,prod;
    maskString(s,c,lim,maskS);
    maskString(t,c,0,maskT);
    reverse(ALL(maskT));
    multiply(maskS,maskT,prod);
    res.clear();
    int numBit=0;
    FORE(it,maskT) if (*it>0) numBit++;
    REP(i,ls) if (prod[i+lt-1]==numBit) res.push_back(i);
}
void process(void) {
    REP(i,4) getOccurPos(ch[i],occurPos[i]);
    int res=0;
    FORE(it,occurPos[0]) {
        bool ok=true;
        FOR(i,1,3) if (!binary_search(ALL(occurPos[i]),*it)) ok=false;
        if (ok) res++;
    }
    cout<<res<<endl;
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    ios::sync_with_stdio(false);
    init();
    process();
    return 0;
}