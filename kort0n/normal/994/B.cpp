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
    long long p[100500];
    long long c[100500];
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    for(int j = 1; j <= n; j++){
        cin >> c[j];
    }
    vector<pair<long long, int> > check;
    for(int i = 1; i <= n; i++){
        pair<long long, int> in;
        in.first = p[i];
        in.second = i;
        check.push_back(in);
    }
    sort(check.begin(), check.end());
    long long ans[100500];
    vector<long long> maxi[100500];
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < maxi[i - 1].size(); j++){
            maxi[i].push_back(maxi[i - 1][j]);
        }
        maxi[i].push_back(c[check[i - 2].second]);
        sort(maxi[i].begin(), maxi[i].end(), greater<long long>());
        while(maxi[i].size() > k){
            maxi[i].pop_back();
        }
    }
    long long sum[100500];
    for(int i = 1; i <= n; i++){
        long long checker = 0;
        for(int j = 0; j < k; j++){
            if(j >= maxi[i].size())break;
            checker += maxi[i][j];
        }
        ans[check[i - 1].second] = checker + c[check[i - 1].second];
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}