#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
vector<int> expr;
int idExpr;
long long calcLv1(void);
long long calcLv2(void) {
    long long res=expr[idExpr];
    while (idExpr+1<expr.size() && expr[idExpr+1]==-2) {
        idExpr+=2;
        res*=expr[idExpr];
    }
    return (res);
}
long long calcLv1(void) {
    long long res=calcLv2();
    while (idExpr+1<expr.size() && expr[idExpr+1]==-1) {
        idExpr+=2;
        res+=calcLv2();
    }
    return (res);
}
vector<int> inpExpr;
void init(void) {
    string inp;
    cin>>inp;
    REP(i,inp.size()) {
        if (inp[i]=='+') inpExpr.push_back(-1);
        else if (inp[i]=='*') inpExpr.push_back(-2);
        else inpExpr.push_back(inp[i]-'0');
    }
}
long long calcExpr(int l,int r) {
    expr.clear();
    idExpr=0;
    FOR(i,l,r) expr.push_back(inpExpr[i]);
    return (calcLv1());
}
long long chooseExpr(int l,int r) {
    long long tmp=calcExpr(l,r);
    expr.clear();
    idExpr=0;
    REP(i,l) expr.push_back(inpExpr[i]);
    expr.push_back(tmp);
    FOR(i,r+1,(int)inpExpr.size()-1) expr.push_back(inpExpr[i]);
    return (calcLv1());
}
void process(void) {
    expr=inpExpr;
    idExpr=0;
    long long res=calcLv1();
    FOR(l,0,(int)inpExpr.size()-1) FOR(r,l+1,(int)inpExpr.size()-1) if (l%2==0 && r%2==0) {
        bool okL=l>0 && inpExpr[l-1]==-2;
        bool okR=r<(int)inpExpr.size()-1 && inpExpr[r+1]==-2;
        if (okL || okR) res=max(res,chooseExpr(l,r));
    }
    cout<<res<<endl;
}
int main(void) {
#ifdef SKY
    //freopen("tmp.txt","r",stdin);
#endif // SKY
    init();
    process();
    return 0;
}