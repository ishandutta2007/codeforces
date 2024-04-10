#include <bits/stdc++.h>
using namespace std;

//Supports efficient flipping, indexing and popping
struct Flipper {
  deque<int> data;
  vector<int> history;
  int flipped;

  Flipper(string init) {
    for (char c : init)
      data.push_back(c-'0');
    flipped = 0;
  }

  //Flip range [0, r)  or [0, size+r) if r <= 0
  void flip(int r = 0) {
    assert(r >= -1 && r <= 5 && r <= size());
    history.push_back(r > 0 ? r : size()+r);
    if (r > 0) {
      int l = 0;
      if (flipped) l = size()-r, r = size();
      reverse(data.begin()+l, data.begin()+r);
      for (int i = l; i < r; i++) {
	data[i] ^= 1;
      }
    } else if (r == 0) {
      flipped ^= 1;
    } else if (r == -1) {
      if (flipped) {
	int cp = data[0];
	data.pop_front();
	data.push_back(cp^1);
      } else {
	int cp = data.back();
	data.pop_back();
	data.push_front(cp^1);
      }
      flipped ^= 1;
    } else assert(0);
  }

  // Delete rightmost element
  void pop() {
    if (!flipped) data.pop_back();
    else data.pop_front();
  }
  int operator[](int i) {
    int n = data.size();
    if (i < 0) i += n;
    if (flipped)
      return data[n-1-i]^1;
    else return data[i];
  }
  int size() {
    return data.size();
  }
};


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string sa, sb;
    cin >> n >> sa >> sb;
    Flipper a(sa), b(sb);

    int done = 0;
    auto pop = [&](int cnt = 1) {
      while (cnt--) a.pop(), b.pop();
      done = 1;
    };

    //Greedy strategies for size >= 5,
    // make k last elements equal in <= k flips for some 1 <= k <= 3

    auto A = [&]() {
      if (a[-1] == b[-1]) pop();
    };
    auto B = [&]() {
      if (a[0] == a[-1]) {
	a.flip();
	pop();
      }
    };
    auto C = [&]() {
      if (b[-2] == b[-1]) {
	a.flip(a[0] == a[1] ? 2 : 1);
	a.flip();
	pop(2);
      }
    };
    auto D = [&]() {
      if (a[0] == a[1]) {
	a.flip(1);
	a.flip();
	pop(2);
      }
    };
    auto E = [&]() {
      if (a[-3] != a[-2]) {
	a.flip(-1);
	a.flip();
	pop(2);
      }
    };
    auto F = [&]() {
      a.flip(-1);
      a.flip();
      a.flip(-1);
      pop(3);
    };

    while (a.size() >= 5) {
      done = 0;
      for (auto f : vector<function<void()>>{A,B,C,D,E,F}) {
	for (int k : {0,1}) { //Exploit symmetry between a and b
	  if (k) swap(a,b);
	  f();
	  if (k) swap(a,b);
	  if (done) break;
	}
	if (done) break;
      }
    }

    //Brute force when size <= 4
    for (int depth = 0; ; depth++) {
      int found = 0;
      for (int mask = 0; mask < 1<<depth*2; mask++) {
	for (int i = 0; i < depth; i++) {
	  a.flip(min((mask>>i*2&3), a.size()));
	}
	int ok = 1;
	for (int i = 0; i < a.size(); i++)
	  if (a[i] != b[i]) ok = 0;
	if (ok) {
	  found = 1;
	  break;
	}
	for (int i = depth-1; i >= 0; i--) {
	  a.flip(min((mask>>i*2&3), a.size()));
	}
	for (int i = 0; i < depth*2; i++)
	  a.history.pop_back();
      }
      if (found) break;
    }


    vector<int> ans = a.history;
    reverse(b.history.begin(), b.history.end());
    for (int r : b.history) ans.push_back(r);

    cout << ans.size() << endl;
    for (int r : ans) cout << r << ' ';
    cout << endl;

    /*for (int r : ans) {
      reverse(sa.begin(), sa.begin()+r);
      for (int i = 0; i < r; i++)
	sa[i] ^= 1;
    }
    assert(sa == sb);*/
    assert((int)ans.size() <= n || (n == 2 && (int)ans.size() == 3));
  }
}