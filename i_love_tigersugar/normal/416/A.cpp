#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const int INF=(int)2e9;
inline void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
inline void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
int main(void) {
    int l=-INF;
    int r=INF;
    int n;
    cin>>n;
    REP(zz,n) {
        string s,t;
        int x;
        cin>>s>>x>>t;
        if (s==">=" && t=="Y") maximize(l,x);
        if (s==">" && t=="Y") maximize(l,x+1);
        if (s=="<=" && t=="Y") minimize(r,x);
        if (s=="<" && t=="Y") minimize(r,x-1);
        if (s==">=" && t=="N") minimize(r,x-1);
        if (s==">" && t=="N") minimize(r,x);
        if (s=="<=" && t=="N") maximize(l,x+1);
        if (s=="<" && t=="N") maximize(l,x);
    }
    if (l<=r) cout << l; else cout << "Impossible";
    return 0;
}