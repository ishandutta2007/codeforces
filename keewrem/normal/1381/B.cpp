#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define ls gfdsgh
#define mpos hgtfrdbh
#define s ghgfdnes

int T;
int N;
int v[5000];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N*2; i++) {
            cin >> v[i];
        }
    //    cout << "lol"<<endl;
        vi mpos;
        int m = 0;
        int mm = 0;
        int ls = 2 * N;
        while (ls > 0) {

            m = 0;
            mm = 0;
            for (int i = 0; i < ls; i++) {
                if (v[i] > m) {
                    m = v[i];
                    mm = i;
                }
            }
            mpos.pb(ls - mm);
            ls = mm;
        //    cout << "kek " << ls<<endl;
        }
    //    for(auto x: mpos)cout << x << " ";
        //cout << endl;
        set<int> s; s.clear();
        s.insert(0);
        vi temp;
        for (int i = 0; i < mpos.size(); i++){
            temp.clear();
            for (int y : s)
                temp.pb(mpos[i] + y);
                for(auto x: temp)s.insert(x);
        }
        if (s.count(N))
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}