#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

const int MAX_N = 1000;

vector<int> school[MAX_N];
vector<int> p, s;

bool mycmp(int i, int j)
{
  return p[i] < p[j];
}

int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  p.resize(n);
  s.resize(n);

  for(auto& el: p)
    cin >> el;

  for(auto& el: s)
  {
    cin >> el;
    --el;
  }

  vector<int> c(k);

  for(auto& el: c)
  {
    cin >> el;
    --el;
  }

  for(int i = 0; i < n; ++i)
  {
    //cout << s[i] + 1 << " <-- " << i + 1 << endl;
    school[s[i]].push_back(i);
  }

  for(int i = 0; i < MAX_N; ++i)
    sort(school[i].rbegin(), school[i].rend(), mycmp);

  int ans = 0;

  for(auto el: c)
  {
    int sch = s[el];
    auto v = school[sch];

    //cout << "sch:" << sch + 1 << endl;

    //for(auto el: v)
      //c//out << el + 1 << " ";

    //cout << endl;

    if(el != v.front())
      ++ans;
  }

  cout << ans << endl;

  //system("pause");
  return 0;
}