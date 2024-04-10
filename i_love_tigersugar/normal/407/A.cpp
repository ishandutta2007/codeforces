#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
vector<ii> va,vb;
int main(void) {
    int a,b;
    cin >> a >> b;
    FOR(i,1,a) FOR(j,1,a) if (i*i+j*j==a*a) va.push_back(ii(i,j));
    FOR(i,1,b) FOR(j,1,b) if (i*i+j*j==b*b) vb.push_back(ii(i,j));
    if (min(va.size(),vb.size())==0) cout << "NO";
    else {
        FORE(it,va) FORE(jt,vb) if (it->fi*jt->fi==it->se*jt->se && it->se!=jt->se) {
            cout << "YES\n0 0\n";
            cout << -it->fi << " " << it->se << "\n";
            cout << jt->fi << " " << jt->se << "\n";
            return 0;
        }
        cout << "NO";
    }
    return 0;
}