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
    int a[10050];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[0] = 0;
    int x[10050];
    for(int i = 0; i < n; i++){
        x[i] = a[i + 1] - a[i];
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        bool checker = true;
        for(int j = 0; j + i < n; j++){
            if(x[j] != x[j + i]){
                checker = false;
                break;
            }
        }
        if(checker){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i < ans.size() - 1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}