#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> set_t;

typedef long long ll;

struct Event {
  int x0, x1, y, type, ei;
};

bool operator<(Event a, Event b) {
  return make_pair(a.x0,a.type) < make_pair(b.x0,b.type);
}

int price[100000], standard[100000], beauty[100000], income[100000], preference[100000];

int ans[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> price[i];
  for (int i = 0; i < n; i++)
    cin >> standard[i];
  for (int i = 0; i < n; i++)
    cin >> beauty[i];
  for (int i = 0; i < m; i++)
    cin >> income[i];
  for (int i = 0; i < m; i++)
    cin >> preference[i];

  vector<Event> events;
  for (int i = 0; i < n; i++) {
    events.push_back({price[i], standard[i], beauty[i], 0, i});
    events.push_back({standard[i], price[i], beauty[i], 2, i});
  }
  for (int i = 0; i < m; i++) {
    events.push_back({income[i], income[i], preference[i], 1, i});
  }

  sort(events.begin(), events.end());

  set_t up, down;
  for (Event e : events) {
    if (e.type == 0) {
      up.insert({e.x0-e.y, e.ei});
      down.insert({e.x0+e.y, e.ei});
    } else if (e.type == 2) {
      up.erase({e.x1-e.y, e.ei});
      down.erase({e.x1+e.y, e.ei});
    } else if (e.type == 1) {
      ans[e.ei] =
	up.order_of_key({e.x0-e.y,1e9})+
	down.order_of_key({e.x0+e.y,1e9})
	-int(up.size());
    }
  }
  for (int i = 0; i < m; i++)
    cout << ans[i] << ' ';
  cout << endl;
}