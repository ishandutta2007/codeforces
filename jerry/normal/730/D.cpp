#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 200005;
const int THRESH = 100000;

int N;
ll r;
ll l[MAX_N];
ll t[MAX_N];

bool ok;
vector<ll> ans;

void add(ll x) {
  if(ok) {
    ans.push_back(x);
    ok = (ans.size() < THRESH);
  }
}

int main() {
  scanf("%d %lld",&N,&r);

  for(int i=0;i<N;i++) {
    scanf("%lld",&l[i]);
  }

  for(int i=0;i<N;i++) {
    scanf("%lld",&t[i]);
  }

  ok = true;

  ll remburst = 0ll;
  ll num = 0ll;

  bool solve = true;
  ll L = 0ll;
  for(int i=0;i<N;i++) {
    ll R = 2ll * l[i] - t[i];
    if (R > l[i]) {
      solve = false;
      break;
    }

    ll app = min(remburst, l[i]);
    remburst -= app;
    L += app;
    R -= app;

    if(remburst == 0 && R > 0) {
      L += (l[i]-app-R) * 2ll;
      num += (R/r);
      while(ok && R >= r) {
        add(L);
        L += r;
        R -= r;
      }
      R %= r;
      if (R > 0) {
        num++;
        add(L);
        L += R;
        remburst = r - R;
      }
    } else if(R <= 0) {
      L += 2ll*(l[i]-app);
    }
  }

  if(!solve) {
    printf("-1\n");
    return 0;
  }

  printf("%lld\n",num);
  if(num <= THRESH) {
    for(auto a: ans) {
      printf("%lld ", a);
    }
    printf("\n");
  }

  return 0;
}