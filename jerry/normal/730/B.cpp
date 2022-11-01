#include <bits/stdc++.h>
using namespace std;

bool alb(int a, int b) {
  printf("? %d %d\n",a+1,b+1);
  fflush(stdout);
  fflush(stdout);
  char c = 'z';
  while(c != '<' && c != '>' && c != '=') {
    c = (char)getchar();
  }
  return c == '<';
}

void solve(int N) {
  if(N == 1) {
    printf("! 1 1\n");
    fflush(stdout);
    fflush(stdout);
    return;
  }

  vector<int> sm;
  vector<int> zg;
  for(int i=0;i+1<N;i+=2) {
    if(alb(i, i+1)) {
      sm.push_back(i);
      zg.push_back(i+1);
    } else { 
      sm.push_back(i+1);
      zg.push_back(i);
    }
  }
  if(N%2 == 1) {
    sm.push_back(N-1);
    zg.push_back(N-1);
  }

  int s = sm[0];
  for(int i=1;i<sm.size();i++) {
    if(alb(sm[i], s)) {
      s = sm[i];
    }
  }

  int l = zg[0];
  for(int i=1;i<zg.size();i++) {
    if(alb(l, zg[i])) {
      l = zg[i];
    }
  }
  printf("! %d %d\n",s+1, l+1);
  fflush(stdout);
  fflush(stdout);
}

int main() {
  int T;
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    int N;
    scanf("%d",&N);
    solve(N);
    fflush(stdout);
  }
  return 0;
}