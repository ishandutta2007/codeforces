#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> i_i;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    int rest = n;
    int diviser = 1;
    vector<i_i> ans;
    while(rest > 0){
        if(rest == 1){
            i_i in = {diviser, 1};
            ans.push_back(in);
            rest--;
            continue;
        }
        if(rest == 2){
            i_i in = {diviser, 1};
            ans.push_back(in);
            rest--;
            diviser = diviser * 2;
            continue;
        }
        if(rest == 3){
            i_i in = {diviser, 2};
            ans.push_back(in);
            diviser *= 3;
            rest -= 2;
            continue;
        }
        i_i in = {diviser, rest - rest / 2};
        ans.push_back(in);
        diviser *= 2;
        rest = rest / 2;
    }
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].second; j++){
            cout << ans[i].first << " ";
        }
    }
    cout << endl;

    return 0;
}