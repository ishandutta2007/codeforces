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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n - 1; i++){
        if(a[i] == a[i + 1]){
            cout << 0 << endl;
            return 0;
        }
    }
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = a[i] & x;
        //cout << v[i] << " " << a[i] << endl;
        if(a[i] == v[i]){
            continue;
        }
        if(lower_bound(a.begin(), a.end(), v[i]) != upper_bound(a.begin(), a.end(), v[i])){
            cout << 1 << endl;
            //cout << a[i] << " " << v[i] << endl;
            return 0;
        }
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n - 1; i++){
        if(v[i] == v[i + 1]){
            cout << 2 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}