#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n, k;
    cin >> n >> k;
    int a[150];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        bool checker = true;
        for(int j = 0; j < ans.size(); j++){
            if(a[i] == a[ans[j]]){
                checker = false;
            }
        }
        if(checker == true){
            ans.push_back(i);
        }
    }
    if(ans.size() < k){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 0; i < k - 1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[k - 1] << endl;
    return 0;
}