#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    vector<int> field;
    int n;
    cin >> n;
    field.push_back(0);
    for(int i = 1; i <= n; i++){
        int in;
        cin >> in;
        field.push_back(in);
    }
    field.push_back(1001);
    int ans = 0;
    for(int i = 0; i < n + 1; i++){
        int j = i + 1;
        while(j < field.size()){
            if(field[j] == field[j - 1] + 1){
                ans = max(ans, j - i - 1);
                j++;
            } else {
                break;
            }
        }
    }
    cout <<ans << endl;
    return 0;
}