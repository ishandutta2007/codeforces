#include<bits/stdc++.h>
#define MAXN 200010
#define int long long
using namespace std;

inline int read(){
  int a = 0;
  char c = getchar();
  while(!isdigit(c))
    c = getchar();
  while(isdigit(c)){
    a = (a << 3) + (a << 1) + (c ^ '0');
    c = getchar();
  }
  return a;
}

int sumBef[MAXN] , sumLas[MAXN] , peo[MAXN] , d , N , b;

bool check(int dir){
  int nL = 1 , nR = N , nowL = 0 , nowR = 0 , rangeL = d + 1 , rangeR = N - d;
  while(nL < nR && (nowL < (N >> 1) - dir || nowR < (N >> 1) - dir)){
    if(nowL < (N >> 1) - dir)
      if(sumBef[rangeL] - nowL * b >= b)
	nowL++;
    if(nowR < (N >> 1) - dir)
      if(sumLas[rangeR] - nowR * b >= b)
	nowR++;
    nL++;
    nR--;
    rangeL = rangeL + d + 1 > N ? N : rangeL + d + 1;
    rangeR = rangeR - d - 1 < 1 ? 1 : rangeR - d - 1;
  }
  return nowL == (N >> 1) - dir && nowR == (N >> 1) - dir;
}

main(){
  N = read();
  d = read();
  b = read();
  for(int i = 1 ; i <= N ; i++)
    sumBef[i] = sumBef[i - 1] + (peo[i] = read());
  for(int i = N ; i ; i--)
    sumLas[i] = sumLas[i + 1] + peo[i];
  int L = 0 , R = N >> 1;
  while(L < R){
    int mid = L + R >> 1;
    if(check(mid))
      R = mid;
    else
      L = mid + 1;
  }
  cout << R;
  return 0;
}