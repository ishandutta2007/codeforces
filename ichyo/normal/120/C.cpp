#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;
typedef long long LL;
static const double EPS = 1e-9;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    int n,k;
    ifs>>n>>k;
    vector<int> a(n);
    REP(i,n)ifs>>a[i];
    int ans = 0;
    REP(i,n){
        if(k*3<=a[i]){
            ans += a[i]-k*3;
        }else{
            ans += a[i]%k;
        }
    }
    ofs<<ans<<endl;
    return 0;
}