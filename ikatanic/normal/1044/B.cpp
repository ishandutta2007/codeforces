#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1010;

vector<int> E[MAX];
bool mine[MAX];
int dad[MAX];

void dfs(int x, int d) {
  dad[x] = d;
  for (int y: E[x]) {
    if (y != d) dfs(y, x);
  }
}

int ask(char c, int x) {
  cout << c << " " << x + 1 << "\n";
  cout.flush();

  int r;
  cin >> r;
  --r;
  return r;
}

void answer(int x) {
  if (x != -1) x++;
  cout << "C " << x << "\n";
  cout.flush();
}

int main(void) {
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) E[i].clear(), mine[i] = false;

    for (int i = 0; i < N - 1; ++i) {
      int A, B;
      cin >> A >> B;
      --A, --B;
      E[A].push_back(B);
      E[B].push_back(A);
    }

    int k1;
    cin >> k1;
    vector<int> my(k1);
    for (int i = 0; i < k1; ++i) {
      cin >> my[i];
      --my[i];
      mine[my[i]] = true;
    }

    dfs(my[0], -1);

    int k2;
    cin >> k2;
    vector<int> his(k2);
    set<int> hisset;
    for (int i = 0; i < k2; ++i) {
      cin >> his[i];
      --his[i];
      hisset.insert(his[i]);
    }

    int one_of_his = ask('B', his[0]);

    while (!mine[one_of_his]) {
      one_of_his = dad[one_of_his];
    }

    int h = ask('A', one_of_his);
    if (hisset.count(h)) {
      answer(one_of_his);
    } else {
      answer(-1);
    }
  }
  return 0;
}