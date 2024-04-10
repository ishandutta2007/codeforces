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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int now = 0;
    for (int i = 0; i < b.size(); i++) {
    	now += (b[i] == '1');
    }
    int now1 = 0;
    for (int i = 0; i < b.size(); i++) {
    	now1 += (a[i] == '1');
    }
    int ans = 0;
    for (int i = 0; i < a.size() - b.size(); i++) {
    	ans += ((now1 - now) % 2 == 0);
    	now1 -= (a[i] == '1');
    	now1 += (a[i + b.size()] == '1');
    }
    ans += ((now1 - now) % 2 == 0);
    cout << ans;
}