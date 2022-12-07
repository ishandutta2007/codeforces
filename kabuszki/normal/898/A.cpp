#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()

typedef vector<int> VI;
typedef pair<int, int> PII;

void jebaj() {
    int n;
    cin >> n;
    if (10 - (n % 10) < n % 10) {
        cout << n + 10 - (n % 10) << "\n";
    } else {
        cout << n - (n % 10) << "\n";
    }

}
int main() {
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}