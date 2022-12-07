#include<bits/stdc++.h>
using namespace std;

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

int a, b, c;
cin >> a >> b >> c;
b --;
c -= 2;
a = min({a, b, c});
cout << 3 * a + 3 << "\n";

}
int main() {
    ios_base::sync_with_stdio();
    cin.tie();
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}