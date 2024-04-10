#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>

#define MP make_pair
#define PB push_back
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair < int,int> pii;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << 18);
const double PI = 3.1415926535;
const double EPS = 1e-9;

int x2,mx[M],p2;


void euclid(){
    for(int i = 2;i<M;i++){
        if(mx[i] != 0) continue;
        for(int j = 2;i*j<M;j++)
            mx[i * j] = i;
    }
}

int main(){
    euclid();
    scanf("%d",&x2);
    p2 = mx[x2];
    int sl = INF;
    for(int i = x2 - p2 + 1;i<=x2;i++){
        if(i - mx[i] + 1 < sl)
            sl = i - mx[i] + 1;
    }
    printf("%d\n", sl);
}