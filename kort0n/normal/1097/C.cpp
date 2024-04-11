#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n;
    map<int, int> before;
    map<int, int> after;
    cin >> n;
    for(int time = 1; time <= n; time++){
        string now;
        cin >> now;
        int plus = 0;
        int max_plus = 0;
        for(int i = 0; i < now.size(); i++){
            if(now[i] == ')'){
                plus++;
            } else {
                plus--;
            }
            max_plus = max(max_plus, plus);
        }
        int minus = 0;
        int max_minus = 0;
        for(int i = now.size() - 1; i >= 0; i--){
            if(now[i] == '(') minus++;
            else minus--;
            max_minus = max(max_minus, minus);
        }
        if(max_plus > 0 && max_minus > 0) continue;
        if(max_plus > 0){
            before[max_plus]++;
            continue;
        }
        if(max_minus > 0){
            after[max_minus]++;
            continue;
        }
        before[0]++;
    }
    int ans = before[0] / 2;
    for(int i = 1; i <= 500000; i++){
        ans += min(after[i], before[i]);
    }
    cout << ans << endl;
    return 0;
}