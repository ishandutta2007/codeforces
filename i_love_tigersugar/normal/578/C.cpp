#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const double INF=5e4+7;
int a[MAX],n;
double b[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
double maxSum(double x) {
    FOR(i,1,n) b[i]=a[i]-x;
    double res=b[1];
    double sum=b[1];
    FOR(i,2,n) {
        sum=b[i]+max(sum,0.0);
        res=max(res,sum);
    }
    FOR(i,1,n) b[i]=-b[i];
    res=max(res,b[1]);
    sum=b[1];
    FOR(i,2,n) {
        sum=b[i]+max(sum,0.0);
        res=max(res,sum);
    }
    return (res);
}
void process(void) {
    double L=-INF;
    double R=INF;
    //cerr<<fixed<<setprecision(9)<<L<<" "<<R<<endl;
    REP(love,227) {
        double M1=(2*L+R)/3;
        double M2=(2*R+L)/3;
        if (maxSum(M1)>maxSum(M2)) L=M1;
        else R=M2;
    }
    //cerr<<fixed<<setprecision(9)<<L<<" "<<R<<endl;
    cout<<fixed<<setprecision(9)<<maxSum((L+R)/2)<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}