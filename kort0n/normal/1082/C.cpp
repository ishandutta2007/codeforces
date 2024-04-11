#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n, m;
    cin >> n >> m;
    vector<int> ability[100050];
    for(int i = 1; i <= n; i++){
        int s, r;
        cin >> s >> r;
        ability[s].push_back(r);
    }
    for(int i = 1; i <= m; i++){
        sort(ability[i].begin(), ability[i].end(), greater<int>());
    }
    vector<int> sum[100050];
    for(int i = 1; i <= m; i++){
        sum[i].push_back(0);
        for(int index = 0; index < ability[i].size(); index++){
            sum[i].push_back(sum[i].back() + ability[i][index]);
        }
        sum[i].push_back(-1);
    }
    int ans = 0;
    int before[100050];
    int after[100050];
    for(int i = 0; i <= m + 1; i++){
        after[i] = i + 1;
        before[i] = i - 1;
    }
    for(int number = 1; number <= n; number++){
        int now = 0;
        int index = 0;
        while(true){
            index = after[index];
            if(index > m) break;
            if(sum[index][number] <= 0){
                int buf = before[index];
                after[buf] = after[index];
                before[after[buf]] = buf;
                continue;
            }
            now += sum[index][number];
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}