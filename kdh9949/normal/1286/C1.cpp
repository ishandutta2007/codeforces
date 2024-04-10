#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define x first
#define y second

const int N = 325;

int n, s[N], sum[26][N], vc;
bitset<N> b[N];
char ans[N];

void addv(int s, int e){
  int flag = 0;
  for(int i = s - 1, j = e - 1; i <= j; i++, j--){
    if(!flag){ b[vc].reset(); flag = 1; }
    else b[vc] = b[vc-1];
    for(int k = i; k <= j; k++) b[vc].flip(k);
    vc++;
  }
}

int ref(){
  /*for(int i = 0; i < vc; i++){
    for(int j = 0; j < n; j++) printf("%d", b[i][j] == 1);
    puts("");
  }*/
  int c = 0;
  for(int i = 0; i < n; i++){
    for(int j = c + 1; j < vc; j++) if(b[j][i]){
      swap(b[j], b[c]);
      break;
    }
    if(!b[c][i]) continue;
    for(int j = c + 1; j < vc; j++) if(b[j][i]) b[j] ^= b[c];
    c++;
  }
  if(c == n){
    for(int i = n-1; i >= 0; i--){
      for(int j = 0; j < i; j++) if(b[j][i]) b[j] ^= b[i];
    }
  }/*
  puts("-----");
  for(int i = 0; i < vc; i++){
    for(int j = 0; j < n; j++) printf("%d", b[i][j] == 1);
    puts("");
  } puts(""); fflush(stdout);
  */return c;
}

void ask(int s, int e){
  printf("? %d %d\n", s, e);
  fflush(stdout);
  int cnt = (e - s + 1) * (e - s + 2) / 2;
  char buf[N];
  while(cnt--){
    scanf("%s", buf);
    int k = strlen(buf);
    if(k > (e - s + 2) / 2) continue;
    for(int i = 0; i < k; i++){
      sum[buf[i] - 'a'][vc + k - 1] ^= 1;
    }
  }
  vc += (e - s + 2) / 2;
}

int main(){
  cin >> n;

  int aa, bb, cc;
  int ra, rb, rc;

  srand(time(0));
  while(true){
    aa = rand() % n + 1;
    bb = rand() % n + 1;
    cc = rand() % n + 1;

    if(aa * (aa + 1) / 2 + bb * (bb + 1) / 2 + cc * (cc + 1) / 2 >
      ceil(0.777 * (n + 1) * (n + 1)) - 1)
      continue;

    ra = 1;
    rb = rand() % (n - bb + 1) + 1;
    rc = n - cc + 1;
    vc = 0;
    addv(ra, ra + aa-1);
    addv(rb, rb + bb-1);
    addv(rc, rc + cc-1);
    int ttt = ref();
    //printf("rank %d\n", ttt);
    if(ttt == n) break;
  }

  vc = 0;
  ask(ra, ra + aa-1);
  ask(rb, rb + bb-1);
  ask(rc, rc + cc-1);

  for(int i = 0; i < 26; i++){
    vc = 0;
    addv(ra, ra + aa-1);
    addv(rb, rb + bb-1);
    addv(rc, rc + cc-1);
    for(int j = 0; j < vc; j++) b[j][n] = sum[i][j];
    ref();
    for(int j = 0; j < n; j++) if(b[j][n]) ans[j] = i + 'a'; 
  }

  printf("! %s\n", ans);
  return 0;
}