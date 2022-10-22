#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Part {
  int cnt;
  int d;
  int l, r;
};

struct Fenwick {
  vector<int> data;
  int n;
  Fenwick(int n_) {
    n = n_+10;
    data.resize(n);
  }
  void add(int i, int v) {
    for (i += 5; i < n; i += i&-i)
      data[i] += v;
  }
  int sum(int i) {
    int sum = 0;
    for (i += 5; i; i -= i&-i) sum += data[i];
    return sum;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<int,int>> cur = {{0,s[0]-'a'}};
    for (char c : s) {
      if (c-'a' != cur.back().second)
	cur.emplace_back(0,c-'a');
      cur.back().first++;
    }

    map<int,Part> part;
    int cnt[26] = {};

    int pos = 0, sum = 0;
    for (auto [c,d] : cur) {
      cnt[d] += c-1;
      sum += c-1;
      if (c-1)
	part[pos] = Part{c-1,d,pos,pos+c-1};
      pos += c;
    }

    int need = 1+max(*max_element(cnt,cnt+26), (sum+1)/2);

    map<int,set<int>> m;
    for (auto [l,p] : part) {
      auto a = part.find(l);
      auto b = next(a);
      if (b == part.end()) break;
      if (a->second.d != b->second.d) {
	m[a->second.d].insert(l);
	m[b->second.d].insert(l);
      }
    }

    vector<pair<int,int>> ans;
    while (1) {
      int mad = max_element(cnt,cnt+26)-cnt;
      int found = 0;
      while (m[mad].size()) {
	auto it = m[mad].begin();
	int lit = *it;
	m[mad].erase(it);

	if (!part.count(lit)) continue;
	auto ait = part.find(lit);
	auto bit = next(ait);
	if (bit == part.end()) continue;
	Part&a = ait->second;
	Part&b = bit->second;
	if ((a.d == mad)+(b.d == mad) != 1) continue;

	found = 1;
	ans.emplace_back(a.r--, b.l++);
	assert(a.d != b.d);
	cnt[a.d]--;
	cnt[b.d]--;
	a.cnt--;
	b.cnt--;

	vector<int> x;
	if (ait != part.begin()) x.push_back(prev(ait)->first);
	if (a.cnt) x.push_back(ait->first);
	if (b.cnt) x.push_back(bit->first);
	if (next(bit) != part.end()) x.push_back(next(bit)->first);

	for (int i = 0; i+1 < (int)x.size(); i++) {
	  int ad = part[x[i]].d, bd = part[x[i+1]].d;
	  if (ad != bd) {
	    m[ad].insert(x[i]);
	    m[bd].insert(x[i]);
	  }
	}

	if (!a.cnt) part.erase(ait);
	if (!b.cnt) part.erase(bit);

	break;
      }

      if (!found) {
	//All are mad
	for (auto [l,p] : part) {
	  for (int c = 0; c < p.cnt; c++) {
	    int a = p.l++;
	    ans.emplace_back(a,a);
	  }
	}
	break;
      }
    }

    ans.emplace_back(-1,n);

    Fenwick tree(n);
    set<int> left;
    for (int i = 0; i < n; i++) {
      tree.add(i,1);
      left.insert(i);
    }

    //cout << s << endl;
    cout << ans.size() << '\n';
    assert((int)ans.size() == need);

    for (auto [l,r] : ans) {
      //#warning change to updating position
      //cout << l << ' ' << r << endl;
      if (l == -1) l = *left.begin();
      if (r == n) r = *left.rbegin();
      cout << tree.sum(l) << ' ' << tree.sum(r) << '\n';
      //continue;
      assert(r >= l);
      assert(left.count(l));
      assert(left.count(r));

      vector<int> torem;
      auto it = left.find(l);

      char last = 0;
      while (1) {
	assert(it != left.end());

	char add = s[*it];
	assert(add != last);
	last = add;

	torem.push_back(*it);
	if (it == left.find(r)) break;
	++it;
      };

      for (int i : torem) {
	tree.add(i,-1);
	left.erase(i);
      }
    }
  }
}