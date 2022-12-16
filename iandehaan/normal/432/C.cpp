#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair
const int maxn = 200000;
int isnprime[maxn];
vector<int> sieve(int n) {
  memset(isnprime, 0, sizeof isnprime);
  isnprime[0] = isnprime[1] = 1;
  vector<int> ps;
  for(int i = 2; i < n; i++)
    if(!isnprime[i]) {
      ps.push_back(i);
      if(n / i >= i)
        for(int j = i * i; j <= n; j += i) isnprime[j] = 1;
    }
  return ps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> primes = sieve(150000);
    reverse(begin(primes), end(primes));

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) a[i]--;
    int pos[n];
    for (int i = 0; i < n; i++) pos[a[i]] = i;

    vector<pair<int, int>> out;
    for (int i = n-1; i >= 0; i--) {
        //cout << i << ' ' << pos[i] << endl;
        while (pos[i] != i) {
            int diff = i-pos[i]+1;
            for (int p : primes) {
                if (p > diff) continue;
                int newpos = pos[i] + p - 1;
                //cout << i << ' ' << pos[i] << ' ' << newpos << endl;
                //cout << "swapping pos " << pos[i] << ' ' << pos[a[newpos]] << endl;
                out.pb(mp(pos[i]+1, pos[a[newpos]]+1));
                swap(pos[i], pos[a[newpos]]);
                swap(a[newpos], a[pos[a[newpos]]]);
                //cout << "a =" << endl;
                //for (int i = 0; i < n; i++) cout << a[i] << ' ';
                //cout << endl;
                
                break;
            }
        }
    }
    cout << out.size() << endl;
    for (pair<int, int> thing : out) cout << thing.first << ' ' << thing.second << endl;
}