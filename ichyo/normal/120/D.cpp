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
    int n,m;
    int c[50][50]={};
    vector<int> A(3);
    ifs>>n>>m;
    REP(y,n)REP(x,m)ifs>>c[y][x];
    REP(i,3)ifs>>A[i];
    sort(A.begin(),A.end());
    int ans = 0;
    FOR(x1,1,m)FOR(x2,x1+1,m){
        vector<int> B(3);
        REP(y,n)REP(x,m){
            if(x<x1){
                B[0] += c[y][x];
            }else if(x<x2){
                B[1] += c[y][x];
            }else{
                B[2] += c[y][x];
            }
        }
        sort(B.begin(),B.end());
        if(A==B){
            ans++;
        }
    }
    FOR(y1,1,n)FOR(y2,y1+1,n){
        vector<int> B(3);
        REP(y,n)REP(x,m){
            if(y<y1){
                B[0] += c[y][x];
            }else if(y<y2){
                B[1] += c[y][x];
            }else{
                B[2] += c[y][x];
            }
        }
        sort(B.begin(),B.end());
        if(A==B)ans++;
    }
    ofs<<ans<<endl;
    return 0;
}