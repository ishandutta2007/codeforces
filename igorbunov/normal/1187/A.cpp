#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;
  
#define int long long
#define endl '\n'

int32_t main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	int n, s, t;
    	cin >> n >> s >> t;
    	int a = (s + t) - n;
    	s -= a;
    	t -= a;
    	cout << max(s, t) + 1 << endl;
    }
}