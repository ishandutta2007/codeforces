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
    int n, m;
    cin >> n >> m;
    vector<int> seq(n);
    vector<int> print(m);
    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }
    for(int i = 0; i < m; i++){
        cin >> print[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(seq[i] == print[j]){
                cout << seq[i] << " ";
                break;
            }
        }
    }
    cout << endl;
    return 0;
}