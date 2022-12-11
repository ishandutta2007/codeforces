#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    set <int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);

    cout << 4 - (int) s.size();

}