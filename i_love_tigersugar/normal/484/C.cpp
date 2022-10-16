#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
struct Permutation {
    vector<int> perm;
    Permutation(){}
    Permutation(int n) {
        perm.clear();
        REP(i,n) perm.push_back(i);
    }
    int& operator [] (int x) {
        return (perm[x]);
    }
    int operator [] (int x) const {
        return (perm[x]);
    }
    Permutation operator * (const Permutation &q) const {
        assert(perm.size()==q.perm.size());
        Permutation res(perm.size());
        REP(i,perm.size()) res[i]=perm[q[i]];
        return (res);
    }
    Permutation operator ^ (int k) const {
        Permutation res(perm.size());
        Permutation mul=*this;
        while (k>0) {
            if (k&1) res=res*mul;
            mul=mul*mul;
            k>>=1;
        }
        return (res);
    }
};
ostream& operator << (ostream &os,const Permutation &p) {
    os<<p.perm.size()<<"|";
    REP(i,p.perm.size()) os<<" "<<p[i];
    return (os);
}
string s;
int n,q;
void init(void) {
    cin>>s>>q;
    n=s.size();
}
Permutation getOrder(int mod,int len) {
    Permutation res(n);
    int id=0;
    REP(i,mod) for (int j=i;j<len;j=j+mod) res[id++]=j;
    return (res);
}
void process(void) {
    Permutation shift(n);
    REP(i,n) shift[i]=(i+1)%n;
    //cerr<<shift<<endl;
    REP(zz,q) {
        int mod,len;
        cin>>len>>mod;
        Permutation order=getOrder(mod,len);
        //cerr<<order<<endl;
        //cerr<<(order*shift)<<endl;
        int tmp=n-len+1;
        Permutation cur=(order*shift)^tmp;
        string newS;
        REP(i,n) newS.push_back(s[cur[(i-tmp+n)%n]]);
        s=newS;
        cout<<s<<"\n";
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);cin.tie(NULL);
    init();
    process();
    return 0;
}