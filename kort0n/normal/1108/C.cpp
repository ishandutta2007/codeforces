#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    string nice[6];
    nice[0] = "RBG";
    nice[1] = "RGB";
    nice[2] = "GBR";
    nice[3] = "GRB";
    nice[4] = "BRG";
    nice[5] = "BGR";
    int n;
    string s;
    cin >> n >> s;
    int ans = 1e9;
    int ans_index = 0;
    for(int index = 0; index < 6; index++) {
        int ans_now = 0;
        string now = nice[index];
        for(int j = 0; j < s.size(); j++) {
            if(s[j] != now[j % 3]) ans_now++;
        }
        if(ans_now < ans) {
            ans = ans_now;
            ans_index = index;
        }
    }
    cout << ans << endl;
    for(int i = 0; i < s.size(); i++) {
        cout << nice[ans_index][i % 3];
    }
    cout << endl;
    return 0;
}