#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef long long LL;
// BIT (0-origin)
struct BIT{
  vector<LL> data;
  BIT(int n) : data(n) { }

  // data[0] + data[1] + ... + data[k]
  LL sum(int k) {
    LL S = 0;
    while(k >= 0){
      S += data[k];
      k = ((k & (k + 1)) - 1);
    }
    return S;
  }

  // v[k] += a;
  void add(int k, LL a) {
    while(k < data.size()){
      data[k] += a;
      k |= k + 1;
    }
  }

  // [a, b]
  LL query(int a, int b){
      LL res = sum(b);
      if(a > 0) res -= sum(a - 1);
      return res;
  }
};

int main(){
    int n, P;
    while(cin >> n >> P){
        vector<int> cnt(n);
        vector<map<int, int>> m(n);
        REP(i, n){
            int a, b;
            cin >> a >> b;
            a--; b--;
            cnt[a] ++;
            cnt[b] ++;
            m[a][b] ++;
            m[b][a] ++;
        }
        long long ans = 0;
        BIT bit(n + 10);
        for(int i = 0; i < n; i++){
            int A = cnt[i];
            for(auto p : m[i]){
                int j = p.first, c = p.second;
                if(j > i) continue;
                if(cnt[j] >= P - A && cnt[j] < P - A + c){
                    ans--;
                }
            }
            ans += bit.query(P - A, n + 5);
            bit.add(cnt[i], 1);
        }
        cout << ans << endl;
    }
    return 0;
}