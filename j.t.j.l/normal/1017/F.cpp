#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 3145728;
const int MM = 1e9 + 7;

ll pw(ll p, ll q){
    ll ret = 1;
    for (; q; q >>= 1){
        if (q & 1)
            ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

unsigned int mp[MAXN];

// pm[0] 0 -> 31
// 1, 5    7, 11      15*6+1, 15*6+5
// 0, 0    1, 1   ... 15, 15               16, 16
// 0,0,2,2,30,30,32,32

// x = i / 96
// y = i % 96 / 6 * 2 + (i % 6 == 5)

vector<int> pl;

int umi = 150;

void fast_sieve() {
    pl.push_back(2);
    pl.push_back(3);
    int n = 300000000;
    int nn = 20000;
    mp[0] = 1;
    int i = 5, x = 0, y = 1;
    while(i < n) {
        if (!((mp[x] >> y) & 1)) {
            if (i <= nn) 
                pl.push_back(i);
        }
        for (size_t j = 0; j < pl.size() && i * pl[j] < n; ++j) {
            int p = pl[j];
            //if (i == 29 || i == 5)
            //    cerr << i << ' ' << j << ' ' << p << endl;
            int q = i * p;
            //if (q == 841){
            //    cerr << "!!!!!" << endl;
            //}
            if (q % 3 != 0 && (q & 1)){
                int xx = q / 96;
                int yy = q % 96 / 6 * 2 + (q % 6 == 5);
                mp[xx] |= (1 << yy);
            }
            //mp[i * p] = 1;
            if (i % p == 0) break;
        }
        i += 2;
        y++; if (y==32){x++; y=0;}
        if (!((mp[x] >> y) & 1)) {
            if (i <= nn) 
                pl.push_back(i);
        }
        for (size_t j = 0; j < pl.size() && i * pl[j] < n; ++j) {
            int p = pl[j];
            int q = i * p;
            if (q % 3 != 0 && (q & 1)){
                int xx = q / 96;
                int yy = q % 96 / 6 * 2 + (q % 6 == 5);
                mp[xx] |= (1 << yy);
            }
            //mp[i * p] = 1;
            if (i % p == 0) break;
        }
        i += 4;
        y++; if (y==32){x++; y=0;}
    }
    /*
    int z = 1, w = 0, cnt = 0;
    cerr << pl.size() << endl;
    for (int x = 0; z <= n; x++){
        for (int y = 0; y < 32 && z <= n; y++){
            if (0 == ((mp[x] >> y) & 1)){
                cnt++;
                //if (cnt <= umi) cerr << z << ' ';
            }
            if (w == 0) z += 4;
            else z += 2;
            w = 1 - w;
        }
    }
    cerr << endl << cnt << endl;
    */
}

void fs(int n) {
  std::vector<int> pl, phi, mp;
  pl.clear();
  phi.assign(n, 1);
  mp.assign(n, 0);
  for (int i = 2; i < n; ++i) {
    if (!mp[i]) {
      pl.push_back(i);
      mp[i] = i;
      phi[i] = i - 1;
    }
    for (size_t j = 0; j < pl.size() && i * pl[j] < n; ++j) {
      int p = pl[j];
      mp[i * p] = p;
      phi[i * p] = phi[i] * (p - !!(i % p));
      if (i % p == 0) break;
    }
  }
  cerr << pl.size() << endl;
  //for (int i = 0; i <= umi; i++)
  //  cerr << pl[i] << ' '; cerr << endl;
}

unsigned int n, A, B, C, D, ans = 0;

unsigned int calc(int p){
    unsigned int q = 0;
    for (unsigned int x = n / p; x != 0; x /= p)
        q += x;
    return q * (D + p * (C + p * (B + p * A)));
}

int main(){
    fast_sieve();
    //fs(3000000);
    scanf("%u%u%u%u%u", &n, &A, &B, &C, &D);
    ans += calc(2);
    ans += calc(3);
    int z = 1, w = 0, cnt = 0;
    for (int x = 0; z <= n; x++){
        for (int y = 0; y < 32 && z <= n; y++){
            if (0 == ((mp[x] >> y) & 1)){
                ans += calc(z);
                //if (cnt <= umi) cerr << z << ' ';
            }
            if (w == 0) z += 4;
            else z += 2;
            w = 1 - w;
        }
    }
    printf("%u\n", ans);
    return 0;
}