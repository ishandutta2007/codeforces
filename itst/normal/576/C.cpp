#include<bits/stdc++.h>
#define MAXN 1000001
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

int output[14];
inline void print(int x){
  int dirN = 0;
  while(x){
    output[dirN++] = x % 10;
    x /= 10;
  }
  while(dirN)
    putchar(output[--dirN] + 48);
  putchar(' ');
}

inline int max(int a , int b){
  return a > b ? a : b;
}

struct Query{
  int l , r , ind;
}now[MAXN];
int N , T=1;

bool cmp(Query a , Query b){
  return a.l / T != b.l / T ? a.l < b.l : ((a.l / T & 1) ^ (a.r > b.r));
}

int main(){
  N = read();
  for(int i = 1 ; i <= N ; i++){
    now[i].l = read();
    now[i].r = read();
    T = max(T , now[i].l);
    now[i].ind = i;
  }
  T = sqrt(T);
  sort(now + 1 , now + N + 1 , cmp);
  for(int i = 1 ; i <= N ; i++)
    print(now[i].ind);
  return 0;
}