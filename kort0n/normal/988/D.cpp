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
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < 32; i++){
        long long distance = 1;
        for(int j = 0; j < i; j++){
            distance = distance * 2;
        }
        for(int j = 0; j < v.size(); j++){
            if(v[j] + 2 * distance > v[v.size() - 1]){
                break;
            }
            if((lower_bound(v.begin(), v.end(), v[j] + distance) != upper_bound(v.begin(), v.end(), v[j] + distance)) && (lower_bound(v.begin(), v.end(), v[j] + 2 * distance) != upper_bound(v.begin(), v.end(), v[j] + 2 * distance))){
                cout << 3 << endl;
                cout << v[j] << " " << v[j] + distance << " " << v[j] + 2 * distance << endl;
                return 0;
            }
        }
    }
    for(int i = 0; i < 32; i++){
        long long distance = 1;
        for(int j = 0; j < i; j++){
            distance = distance * 2;
        }
        for(int j = 0; j < v.size(); j++){
            if(v[j] + distance > v[v.size() - 1]){
                break;
            }
            if(lower_bound(v.begin(), v.end(), v[j] + distance) != upper_bound(v.begin(), v.end(), v[j] + distance)){
                cout << 2 << endl;
                cout << v[j] << " " << v[j] + distance << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
    cout << v[0] << endl;
    return 0;
}