#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;



void jebaj() {
    int n;
    cin >> n;
    VI v(n);
    REP(i, n) {
        cin >> v[i];
    }
    int maksi = *max_element(ALL(v));
    for (auto& a : v) a = (a == maksi);
    for (int i = 1; i < n; i++) if (v[i] == 1) v[i] += v[i - 1];
    cout << *max_element(ALL(v)) << "\n";
}

#undef int

int main() {

    #define int long long
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}