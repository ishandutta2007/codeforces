#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;

int a[10][3];
int b[10][3];
int c[10][3];

ll dist[30];

bool check(void){
    int i,j,k=0;
    
    REP(i,8) REP(j,i){
        ll x = b[i][0] - b[j][0];
        ll y = b[i][1] - b[j][1];
        ll z = b[i][2] - b[j][2];
        dist[k] = x*x+y*y+z*z;
        k++;
    }
    
    sort(dist, dist+28);
    if(dist[0] == 0) return false;
    REP(i,12) if(dist[i] != dist[0]) return false;
    REP(i,12) if(dist[12+i] != dist[0] * 2) return false;
    REP(i,4) if(dist[24+i] != dist[0] * 3) return false;
    return (true);    
    ll X = 0, Y = 0, Z = 0, S = 0;
    REP(i,8){
        X += b[i][0];
        Y += b[i][1];
        Z += b[i][2];
    }
    
    REP(i,8){
        ll x = X - 8 * b[i][0];
        ll y = Y - 8 * b[i][1];
        ll z = Z - 8 * b[i][2];
        ll d = x*x+y*y+z*z;
        if(i == 0) S = d;
        else if(d != S) return false;
    }
    
    return true;
}

bool dfs(int pos){
    int i,j;
    
    if(pos == 8){
        if(check()){
            REP(i,8) REP(j,3) c[i][j] = b[i][j];
            return true;
        }
        return false;
    }
    
    int p[] = {0, 1, 2};
    do {
        REP(i,3) b[pos][i] = a[pos][p[i]];
        if(dfs(pos+1)) return true;
    } while(next_permutation(p, p+3));
    
    return false;
}

int main(void){
    int i,j;
    
    REP(i,8) REP(j,3) cin >> a[i][j];
    REP(i,3) b[0][i] = a[0][i];
    bool ans = dfs(1);
    
    if(ans){
        cout << "YES" << endl;
        REP(i,8) cout << c[i][0] << ' ' << c[i][1] << ' ' << c[i][2] << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}