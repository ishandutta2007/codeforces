#include <iostream>
#include <set>

using namespace std;

int main(int argc, char** argv)
{
  int n, temp;
  set<int> s;
  cin >> n;

  for(int i = 0; i < n; ++i)
  {
    cin >> temp;

    if(temp != 0)
      s.insert(temp);
  }

  cout << s.size() << endl;

  return 0;
}