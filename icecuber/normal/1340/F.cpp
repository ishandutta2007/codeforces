#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll,ll>> bpow = {{1,1}};

struct HashArr {
  const ll base = 137137, mod[2] = {(int)1e9+7,(int)1e9+9};

  vector<pair<ll,ll>> h;
  void init(vector<int>&a) {
    int n = a.size();
    h.resize(n+1);
    bpow[0] = {1,1};
    for (int i = 0; i < n; i++) {
      h[i+1].first = (h[i].first*base+a[i])%mod[0];
      h[i+1].second = (h[i].second*base+a[i])%mod[1];
    }
    while ((int)bpow.size() < n+1) {
      bpow.push_back(
		     {bpow.back().first*base%mod[0],
			 bpow.back().second*base%mod[1]});
    }
  }
  ll getHash(int l, int r) {
    assert(r >= l);
    ll a = (bpow[r-l].first*h[l].first-h[r].first+mod[0])%mod[0];
    ll b = (bpow[r-l].second*h[l].second-h[r].second+mod[1])%mod[1];
    return a<<32|b;
  }
};


const int nax = 1e5;
const int B = 300;

struct Block {
  bool bad;
  vector<int> ends, starts;
  HashArr endh, starth;
  void init(vector<int>&a, int l, int r) {
    ends.clear(), starts.clear();
    bad = false;
    for (int i = l; i < r; i++) {
      if (a[i] < 0) {
	if (starts.empty()) {
	  ends.push_back(-a[i]);
	} else {
	  if (starts.back() != -a[i]) {
	    bad = true;
	    return;
	  } else {
	    starts.pop_back();
	  }
	}
      } else {
	assert(a[i] > 0);
	starts.push_back(a[i]);
      }
    }
    reverse(ends.begin(), ends.end());
    endh.init(ends);
    starth.init(starts);
  }
};


Block block[nax/B+2];

struct Range {
  Block&block;
  int l, r;
  Range(Block&b) : block(b) {
    l = 0;
    r = b.starts.size();
  }
};

struct Joiner {
  bool bad;
  Joiner() {
    bad = false;
  }
  /*
  vector<int> starts;
  void operator()(const Block&b) {
    bad |= b.bad;
    if (bad) return;
    bad = true;
    int bsz = b.ends.size(), msz = starts.size();
    if (msz < bsz) return;
    for (int i = 0; i < bsz; i++) {
      if (starts[msz-bsz+i] != b.ends[i]) return;
    }
    starts.resize(msz-bsz);
    for (int v : b.starts)
      starts.push_back(v);
    bad = false;
    }*/

  vector<Range> starts;
  void operator()(Block&b) {
    bad |= b.bad;
    if (bad) return;
    bad = true;

    int bl = 0, br = b.ends.size();
    while (br > bl) {
      if (starts.empty()) return;
      Range&r = starts.back();
      int aw = r.r-r.l;
      int w = min(aw, br-bl);
      //assert(w <= 1);
      //if (w && r.block.starts[r.r-1] != b.ends[br-1]) return;
      if (r.block.starth.getHash(r.r-w, r.r) != b.endh.getHash(br-w, br)) return;
      br -= w;
      r.r -= w;
      if (r.r == r.l) starts.pop_back();
    }

    if (b.starts.size())
      starts.emplace_back(b);
    bad = false;
  }
};


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  for (int i = 0; i < n; i += B) {
    block[i/B].init(a, i, min(i+B,n));
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, t;
      cin >> i >> t;
      i--;
      a[i] = t;
      int l = i/B*B;
      block[i/B].init(a, l, min(l+B,n));
    } else if (type == 2) {
      int l, r;
      cin >> l >> r;
      l--;

      vector<Block> tmps;
      tmps.reserve(2);
      Joiner joiner;
      /*{
	Block b;
	b.init(a,l,r);
	joiner(b);
	}*/

      int i = l;
      while (i < r) {
	int ni = min(i/B*B+B, r);
	if (i%B == 0 && ni%B == 0) {
	  joiner(block[i/B]);
	} else {
	  tmps.push_back(Block());
	  tmps.back().init(a,i,ni);
	  joiner(tmps.back());
	}
	i = ni;
      }
      cout << (joiner.bad || joiner.starts.size() ? "No" : "Yes") << '\n';
    } else assert(0);
  }
}