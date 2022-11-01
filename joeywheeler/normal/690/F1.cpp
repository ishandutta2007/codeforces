#include <bits/stdc++.h>

#define INF 1000000010
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define sz(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/

#define MAX_N 10005

int N;
vector <int> allE[MAX_N];
vector <int> allC[MAX_N];
int par[MAX_N];

void makeTree(int c) {
    FO (i,0,allE[c].size()) {
        if (allE[c][i] != par[c]) {
            par[allE[c][i]] = c;
            allC[c].push_back (allE[c][i]);
            makeTree(allE[c][i]);
        }
    }
}

ll getAns(int c) {
    ll ans = 0;
    FO (i,0,allC[c].size()) {
        ans += getAns(allC[c][i]);
        ans += allC[allC[c][i]].size();
    }
    ans += (allC[c].size())*(allC[c].size()-1)/2;
    return ans;
}


int main() {
    scanf ("%d", &N);
    FO (i,0,N-1) {
        int _a, _b;
        scanf ("%d %d", &_a, &_b);
        _a--;
        _b--;
        allE[_b].push_back (_a);
        allE[_a].push_back (_b);
    }
    makeTree(0);
    printf ("%I64d\n", getAns(0));
    return 0;
}