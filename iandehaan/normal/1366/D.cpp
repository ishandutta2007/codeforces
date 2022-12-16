#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

const int maxn = 10000002;
int fac[maxn];
int bla[maxn];
void sieve(int n) {
  //memset(isnprime, 0, sizeof isnprime);
  //isnprime[0] = isnprime[1] = 1;
  for(int i = 2; i < n; i++)
    if(fac[i] == 0) {
        for(int j = i + i; j <= n; j += i){
            if (fac[j] != 0) {
                bla[j] = max(1, bla[j]);
                bla[j] *= i;
            }
            else fac[j] = i;
        } 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(10000001);

    int n;
    cin >> n;
    pair<int, int> out[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        //cout << x << ' ' << facs[x].size() << endl;
        if (!bla[x]) out[i] = mp(-1, -1);
        else out[i] = mp(fac[x], bla[x]);
    }
    for (int i = 0; i < n; i++) cout << out[i].first << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << out[i].second << ' ';
    cout << '\n';
}