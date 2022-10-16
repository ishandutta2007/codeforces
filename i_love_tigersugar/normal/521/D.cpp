#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
using namespace std;
int compFraction(long long p1,long long q1,long long p2,long long q2) {
    //cerr<<p1<<" "<<q1<<" "<<p2<<" "<<q2<<endl;
    long long x1=p1/q1;
    long long x2=p2/q2;
    if (x1!=x2) return ((x1>x2)-(x1<x2));
    long long r1=p1-x1*q1;
    long long r2=p2-x2*q2;
    if (r1==0 && r2==0) return (0);
    if (r1==0) return (-1);
    if (r2==0) return (1);
    return (-compFraction(q1,r1,q2,r2));
}
long long gcd(long long a,long long b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a%=b; else b%=a;
    }
}
struct Fraction {
    long long p,q;
    Fraction() {
        p=0;q=1;
    }
    Fraction(long long p) {
        this->p=p;
        this->q=1;
    }
    Fraction(long long p,long long q) {
        long long t=gcd(p,q);
        this->p=p/t;
        this->q=q/t;
    }
    bool operator < (const Fraction &x) const {
        return (compFraction(p,q,x.p,x.q)<0);
    }
};
template<class T>
    struct Bonus {
        T value;
        int type,id;
        Bonus() {
            value=type=id=0;
        }
        Bonus(const T &v,int t,int i) {
            value=v;type=t;id=i;
        }
        bool operator < (const Bonus &x) const {
            return (value<x.value);
        }
    };
template<class T>
    bool CompType(const Bonus<T> &a,const Bonus<T> &b) {
        return (a.type<b.type);
    }
int nSkill,nBonus,lim;
int staVal[MAX];
Bonus<int> maxAssign[MAX];
vector<Bonus<int> > add[MAX];
vector<Bonus<Fraction> > bonus;
void process(void) {
    scanf("%d%d%d",&nSkill,&nBonus,&lim);
    FOR(i,1,nSkill) scanf("%d",&staVal[i]);
    FOR(i,1,nBonus) {
        int val,type,pos;
        scanf("%d%d%d",&type,&pos,&val);
        if (type==1) maxAssign[pos]=max(maxAssign[pos],Bonus<int>(val,type,i));
        if (type==2) add[pos].push_back(Bonus<int>(val,type,i));
        if (type==3) bonus.push_back(Bonus<Fraction>(val,type,i));
    }
    FOR(i,1,nSkill) {
        if (maxAssign[i].value>staVal[i]) add[i].push_back(Bonus<int>(maxAssign[i].value-staVal[i],1,maxAssign[i].id));
        sort(ALL(add[i]));
        reverse(ALL(add[i]));
        long long sum=staVal[i];
        FORE(it,add[i]) {
            bonus.push_back(Bonus<Fraction>(Fraction(sum+it->value,sum),it->type,it->id));
            sum+=it->value;
        }
    }
    sort(ALL(bonus));
    reverse(ALL(bonus));
    vector<Bonus<Fraction> > res;
    REP(i,bonus.size()) if (i<lim) res.push_back(bonus[i]);
    sort(ALL(res),CompType<Fraction>);
    printf("%d\n",(int)res.size());
    REP(i,res.size()) {
        if (i>0) printf(" ");
        printf("%d",res[i].id);
    }
    printf("\n");
}
int main(void) {
    process();
    return 0;
}