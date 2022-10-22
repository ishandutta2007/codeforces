#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
  int v, nxt, id;
};
struct DNode {
  int v, nxt, prv;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].v;
      a[i].id = i+1;
      a[i].nxt = (i+1)%n;
    }

    vector<int> bv;
    for (int i = 0; i < n; i++) {
      if (gcd(a[i].v, a[a[i].nxt].v) == 1) {
        bv.push_back(i);  
      }
    }

    int bsz = bv.size();
    vector<DNode> b(bsz);
    for (int i = 0; i < (int)bv.size(); i++) {
      b[i].v = bv[i];
      b[i].nxt = (i+1)%bsz;
      b[i].prv = (i-1+bsz)%bsz;
    }


    int cur = 0;
    vector<int> ans;
    
    while (bsz) {
      int ai = b[cur].v;
      if (0) {
        cout << "bsz " << bsz << endl;
        int p = ai;
        do {
          cout << a[p].v << ' ';
          p = a[p].nxt;
        } while (p != ai);
        cout << endl;
      }

      int d = a[ai].nxt;

      //cout << "del " << a[d].v << endl;
      //Delete d
      ans.push_back(a[d].id);
      a[ai].nxt = a[d].nxt;

      if (a[b[b[cur].nxt].v].id == a[d].id) {
        //cout << "= id" << endl;
        //delete b[cur].nxt
        if (!--bsz) break;
        int r = b[cur].nxt;
        int rr = b[r].nxt;
        b[cur].nxt = rr;
        b[rr].prv = cur;
      }

      if (gcd(a[ai].v, a[a[ai].nxt].v) != 1) {
        //cout << "gcd != 1" << endl;
        if (!--bsz) break;
        //delete b[cur]
        int l = b[cur].prv;
        int r = b[cur].nxt;
        b[l].nxt = r;
        b[r].prv = l;
        cur = l;
      }
      cur = b[cur].nxt;
    }

    cout << ans.size() << ' ';
    for (int i : ans) cout << i << ' ';
    cout << endl;

    //cout << endl << endl;
  }
}