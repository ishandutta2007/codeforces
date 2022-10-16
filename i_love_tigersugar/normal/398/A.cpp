#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
const char s[]="ox";
int a,b;
ll value(int k) {
    ll add=k-1+1LL*(a-k+1)*(a-k+1);
    int p=b/(k+1);
    ll sub=1LL*(p+1)*(p+1)*(b%(k+1))+1LL*p*p*(k+1-b%(k+1));
    return (add-sub);
}
void process(void) {
    cin >> a >> b;
    if (b<2) {
        cout << 1LL*a*a-1LL*b*b << "\n";
        REP(i,a) cout << s[0];
        REP(i,b) cout << s[1];
        return;
    }
    if (a==0) {
        cout << -1LL*b*b << "\n";
        REP(i,b) cout << s[1];
        return;
    }
    int k=1;
    ll best=-INF;
    FOR(i,1,a) if (i<=a && i<b) {
        ll tmp=value(i);
        if (tmp>best) {
            best=tmp;
            k=i;
        }
    }
    cout << best << "\n";
    bool mode=false;
    int ca=0;
    int cb=0;
    REP(i,2*k+1) {
        if (mode) {
            int no;
            if (ca<1) no=a-k+1; else no=1;
            REP(i,no) cout << "o";
            ca++;
        }
        else {
            int no;
            if (cb<b%(k+1)) no=b/(k+1)+1; else no=b/(k+1);
            REP(i,no) cout << "x";
            cb++;
        }
        mode=!mode;
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    process();
    return 0;
}