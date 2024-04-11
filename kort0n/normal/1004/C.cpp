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
    long long n;
    cin >> n;
    long long a[150000];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<long long> left;
    vector<long long> right;
    bool checker[150000];
    for(int i = 0; i <= 100000; i++){
        checker[i] = false;
    }
    for(int i = 1; i <= n; i++){
        if(checker[a[i]] == false){
            left.push_back(i);
            checker[a[i]] = true;
        }
    }
    for(int i = 0; i <= 100000; i++){
        checker[i] = false;
    }
    for(int i = n; i >= 1; i--){
        if(checker[a[i]] == false){
            right.push_back(i);
            checker[a[i]] = true;
        }
    }
    long long ans = 0;
    for(int i = 0; i < right.size(); i++){
        ans += distance(left.begin(), lower_bound(left.begin(), left.end(), right[i]));
    }
    cout << ans << endl;
    return 0;
}