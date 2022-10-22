#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int MAXN = 1010, sigma = 14;

int term[MAXN], len[MAXN], to[MAXN][sigma], link[MAXN], sz = 1;
int score[MAXN];

int add_str(string s) {
  int cur = 0;
  for(auto c: s)
    {
      if(!to[cur][c - 'a'])
        {
	  to[cur][c - 'a'] = sz++;
	  len[to[cur][c - 'a']] = len[cur] + 1;
        }
      cur = to[cur][c - 'a'];
    }
  term[cur] = cur;
  return cur;
}

void push_links() {
  int que[sz];
  int st = 0, fi = 1;
  que[0] = 0;
  while(st < fi) {
    int V = que[st++];
    int U = link[V];

    score[V] += score[U];

    if(!term[V]) term[V] = term[U];
    for(int c = 0; c < sigma; c++)
      if(to[V][c])
	{
	  link[to[V][c]] = V ? to[U][c] : 0;
	  que[fi++] = to[V][c];
	}
      else
	{
	  to[V][c] = to[U][c];
	}
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k;
  cin >> k;

  while (k--) {
    string s;
    cin >> s;
    int cost;
    cin >> cost;
    int p = add_str(s);
    score[p] += cost;
  }
  push_links();

  string text;
  cin >> text;
  vector<ll> dp(sz<<14, -1e18);
  dp[0] = 0;
  vector<int> ends(sz);
  vector<ll> acc(sz);

  auto reset = [&]() {
    for (int i = 0; i < sz; i++) ends[i] = i;
    fill(acc.begin(), acc.end(), 0);
  };
  reset();

  vector<ll> ndp(sz<<14, -1e18);

  auto push = [&]() {
    fill(ndp.begin(), ndp.end(), -1e18);
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < 1<<14; j++) {
	ll&v = ndp[(ends[i]<<14)+j];
	v = max(v, dp[(i<<14)+j]+acc[i]);
      }
    }
    swap(ndp, dp);
    reset();
  };

  auto choose = [&]() {
    fill(ndp.begin(), ndp.end(), -1e18);
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < 1<<14; j++) {
	if (dp[(i<<14)+j] < -1e17) continue;
	for (int c = 0; c < 14; c++) {
	  if (j>>c&1) continue;
	  ll&v = ndp[ (to[i][c]<<14)+(j | 1<<c)];
	  v = max(v, dp[(i<<14)+j] + score[to[i][c]]);
	}
      }
    }
    swap(ndp, dp);
  };

  for (int ti = 0; ti < (int)text.size(); ti++) {
    if (text[ti] != '?') {
      int d = text[ti]-'a';
      for (int i = 0; i < sz; i++) {
	ends[i] = to[ends[i]][d];
	acc[i] += score[ends[i]];
      }
    } else {
      push();
      choose();
      reset();
    }
  }
  push();
  ll ans = -1e18;
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < 1<<14; j++) {
      ans = max(ans, dp[(i<<14)+j]);
    }
  }
  cout << ans << endl;
}