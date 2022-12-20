#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

// Returns all prime numbers in [0,n]
const int maxn = 5000002;
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
ll numdivs[5000001];
ll pref[5000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> primes = sieve(180);
    vector<int> blah = sieve(5000001);
    //cout << primes.size() << endl;
    
    
    numdivs[0] = 0;
    numdivs[1] = 0;
    for (int i = 2; i <= 5000000; i++) {
        int tst = i;
        numdivs[i] = 0;
        for (int div : primes) {
            if (div > tst) break;
            while (tst % div == 0) {
                tst /= div;
                numdivs[i]++;
            }
        }
        if (tst != 1) {
            if (isnprime[tst] == 0) numdivs[i]++;
            else numdivs[i] += 2;
        }
    }
    
    pref[0] = 0;
    for (int i = 1; i <= 5000000; i++) {
        pref[i] = pref[i-1] + numdivs[i];
    }

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << pref[a]-pref[b] << '\n';
    }
}