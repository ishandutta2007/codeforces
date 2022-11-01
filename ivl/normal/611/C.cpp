#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int h, w;
char in[505][505];

#define right right2222

int down[505][505];
int right[505][505];

int main(){

  cin >> h >> w;
  REP(i,h) scanf("%s", in[i]);

  REP(i,h-1) REP(j,w) if (in[i][j] == '.' && in[i+1][j] == '.') down[i+1][j+1] = 1;
  REP(i,h) REP(j,w-1) if (in[i][j] == '.' && in[i][j+1] == '.') right[i+1][j+1] = 1;

  REP(i,h+1) REP(j,w+1){
    down[i+1][j] += down[i][j];
    down[i][j+1] += down[i][j];
    down[i+1][j+1] -= down[i][j];
    right[i+1][j] += right[i][j];
    right[i][j+1] += right[i][j];
    right[i+1][j+1] -= right[i][j];
  }

  int q;
  cin >> q;
  REP(ttt,q){
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    printf("%d\n", down[r2-1][c2]-down[r1-1][c2]-down[r2-1][c1-1]+down[r1-1][c1-1]+
	   right[r2][c2-1]-right[r1-1][c2-1]-right[r2][c1-1]+right[r1-1][c1-1]
	   );
  }
  
}