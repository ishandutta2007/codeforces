#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n, t;
    int ret;
    cin >> n >> t;
    int ans[305];
    int before = 0;
    int now = t;
    for(int index = 1; index < n; index++){
        for(int time = 1; time <= 20; time++){
            cout << "? " << index + 1 << " " << n << endl;
            cin >> ret;
            if(ret == -1) return 0;
            cout << "? " << index + 1 << " " << n << endl;
            cin >> ret;
            if(ret == -1) return 0;
            if(now != ret) break;
        }
        if(now == ret){
            int before2 = index / 2;
            if(before == before2){
                ans[index] = 0;
                continue;
            }
            before = before2;
            ans[index] = 1;
            continue;
        }
        //int before2 = (now + index + ret) / 2;
        ans[index] = (index + 1 - 2 * before - ret + now) / 2;
        while(ret != now){
            cout << "? " << index + 1 << " " << n << endl;
            cin >> ret;
            if(ret == -1) return 0;
            cout << "? " << index + 1 << " " << n << endl;
            cin >> ret;
            if(ret == -1) return 0;
        }
        if(ans[index] == 1) before++;
    }
    ans[n] = t;
    for(int i = 1; i < n; i++){
        ans[n] -= ans[i];
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}