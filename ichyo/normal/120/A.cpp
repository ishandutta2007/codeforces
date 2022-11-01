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
    string s;
    int n;
    ifs>>s>>n;
    int m = (s[0]=='f');
    int a = (n+m)%2;
    string ans;
    if(a) ans = "R";
    else ans = "L";
    ofs<<ans<<endl;
    return 0;
}