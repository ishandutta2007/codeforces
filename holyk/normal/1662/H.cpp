#include <bits/stdc++.h>
#define LL long long
using namespace std;
map<int, int> mp;
vector<int> q;
int w, l;

bool chk(int i) {
  if(w % i == 0 && (l - 2) % i == 0) return 1;
  if(w % i == 0 && (w - 2) % i == 0 && (l - 1) % i == 0) return 1;
  if((w - 1) % i == 0 && (l - 1) % i == 0) return 1;
  if((w - 2) % i == 0 && l % i == 0) return 1;
  if(l % i == 0 && (l - 2) % i == 0 && (w - 1) % i == 0) return 1;
  return 0;
}

void gao(int i) {
  if(mp.count(i)) return ;
  if(!chk(i)) return ;
  mp[i] = 1, q.emplace_back(i);
}

int main()
{
  int T; scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &w, &l);
    mp.clear(), q.clear();
    for(int i = 1; i * i <= w; i++) if(w % i == 0 || (w - 1) % i == 0 || (w - 2) % i == 0) {
	gao(i);
	if(w % i == 0) gao(w / i);
	if((w - 1) % i == 0) gao((w - 1) / i);
	if((w - 2) % i == 0) gao((w - 2) / i);
      }
    printf("%d", (int)q.size());
    sort(q.begin(), q.end());
    for(auto u : q) {
      printf(" %d", u);
    } puts("");
  }
  return 0;
}