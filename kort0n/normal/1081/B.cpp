#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    int a[200000];
    int ans[200000];
    for(int i = 1; i <= n; i++){
        ans[i] = INF;
        cin >> a[i];
    }
    int index = 1;
    vector<int> v[200000];
    for(int i = 1; i <= n; i++){
        int number = n - a[i];
        v[number].push_back(i);
        if(v[number].size() == number){
            for(int j= 0; j < number; j++){
                ans[v[number][j]] = index;
            }
            index++;
            v[number].clear();
        }
    }
    for(int i = 1; i <= n; i++){
        if(ans[i] == INF){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    for(int i = 1; i <= n; i++){
        cout << ans[i];
        if(i < n) cout << " ";
    }
    cout << endl;
    return 0;
}