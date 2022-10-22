#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

pair<ll,ll> mem[10][10][20][10];
int done[10][10][20][10];

ll pow10[20];

pair<ll,ll> g(ll max_left, ll n);
pair<ll,ll> f(ll max_left, int digit, int digit_pos, int last_digit) {
  if (digit == 0) return {0,last_digit};
  pair<ll,ll>&memo = mem[max_left][digit][digit_pos][last_digit];
  if (memo.first == -1) {
    assert(!done[max_left][digit][digit_pos][last_digit]++);
    ll n = pow10[digit_pos]*digit+last_digit;
    ll ans = 0;
    while (n >= pow10[digit_pos]*digit) {
      ll max_digit = max_left;
      for (int i = 0; n/pow10[i]; i++)
	max_digit = max(max_digit, n/pow10[i]%10);
      n -= max_digit;
      ans++;
    }
    auto p = g(max_left, n);
    memo = {ans+p.first, p.second};
  }
  //cout << max_left << ' ' << digit << ' ' << digit_pos << ' ' << last_digit << ": " << memo.first << ' ' << memo.second << endl;
  return memo;
}

pair<ll,ll> g(ll max_left, ll n) {
  ll n0 = n;
  ll moves = 0;
  int i = 1;
  while (n > 9) {
    //cout << n << endl;
    ll new_max_left = max_left;
    for (int j = i+1; n/pow10[j]; j++)
      new_max_left = max(new_max_left, n/pow10[j]%10);
    int digit = n/pow10[i]%10;
    int digit_pos = i;
    int last_digit = n%10;
    auto p = f(new_max_left, digit, digit_pos, last_digit);
    moves += p.first;
    i++;
    n = n/pow10[i]*pow10[i] + p.second;
  }
  //cout << max_left << ' ' << n0 << ": " << moves << ' ' << n << endl;
  return {moves, n};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  pow10[0] = 1;
  for (int i = 1; i < 20; i++)
    pow10[i] = pow10[i-1]*10;

  fill_n((pair<ll,ll>*)mem, 10*10*20*10, make_pair(-1ll,0ll));

  ll n;
  cin >> n;
  auto p = g(0, n);
  if (p.second) p.first++;
  cout << p.first << endl;
}