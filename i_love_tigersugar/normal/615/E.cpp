#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define left    ___left
#define right    ___right
#define int  long long
using namespace std;
const int INF=(int)1e9+7;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int roundCount(int round) {
    return (6*round);
}
int roundSum(int round) {
    return (6*round*(round+1)/2);
}
int findRound(int n) {
    int L=1;
    int R=INF;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (roundSum(L)>=n?L:R);
        int M=(L+R)>>1;
        if (roundSum(M)>=n) R=M; else L=M+1;
    }
}
pair<int,int> cord(int n) {
    if (n==0) return (make_pair(0,0));
    int c=findRound(n);
    int prev=roundSum(c-1);
    if (n<=prev+c) return (make_pair(c,n-prev));
    if (n<=prev+2*c) return (make_pair(prev+2*c-n,c));
    if (n<=prev+3*c) return (make_pair(prev+2*c-n,prev+3*c-n));
    if (n<=prev+4*c) return (make_pair(-c,prev+3*c-n));
    if (n<=prev+5*c) return (make_pair(n-prev-5*c,-c));
    return (make_pair(n-prev-5*c,n-prev-6*c));
}
bool inRound(int x,int y,int c) {
    if (0<=y && y<=c && x==c) return (true);
    if (0<=x && x<=c && y==c) return (true);
    if (0<=y && y<=c && y-x==c) return (true);
    if (-c<=y && y<=0 && x==-c) return (true);
    if (-c<=x && x<=0 && y==-c) return (true);
    if (0<=x && x<=c && x-y==c) return (true);
    return (false);
}
int findRound(int x,int y) {
    int res=1;
    while (!inRound(x,y,res)) res++;
    return (res);
}
int number(int x,int y) {
    if (x==0 && y==0) return (0);
    int c=findRound(x,y);
    int prev=roundSum(c-1);
    if (1<=y && y<=c && x==c) return (prev+y);
    if (0<=x && x<=c && y==c) return (prev+2*c-x);
    if (0<=y && y<=c && y-x==c) return (prev+2*c-x);
    if (-c<=y && y<=0 && x==-c) return (prev+3*c-y);
    if (-c<=x && x<=0 && y==-c) return (prev+5*c+x);
    return (prev+5*c+x);
}
const int dx[]={0,1,0,-1,-1,1};
const int dy[]={1,0,-1,0,-1,1};
#undef int
int main(void) {
    long long t;
    cin>>t;
    long long x=cord(t).fi;
    long long y=cord(t).se;
    cout<<2*x-y<<" "<<2*y<<endl;
    return 0;
}