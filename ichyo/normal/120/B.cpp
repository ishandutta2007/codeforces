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
    ofstream ofs("output.txt");
    ifstream ifs("input.txt");
    int n,k;
    ifs>>n>>k;
    vector<int> a(n);
    REP(i,n)ifs>>a[i];
    k--;
    while(true){
        if(a[k]==1){
            ofs<<k+1<<endl;
            break;
        }
        k=(k+1)%n;
    }
    return 0;
}