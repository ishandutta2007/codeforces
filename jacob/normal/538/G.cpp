#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <sstream>
using namespace std;

typedef long long ll;

struct TEvent {
  ll x = 0, y = 0, t = 0;
};

const ll INF = LLONG_MAX / 2;

void assign_max(ll& v, ll candidate) {
  if (candidate > v)
    v = candidate;
}

void assign_min(ll& v, ll candidate) {
  if (candidate < v)
    v = candidate;
}

inline ll lbdiv(ll a, ll b) {
  if (a >= 0)
    return a / b;
  else
    return (a - b + 1) / b;
}

inline ll ubdiv(ll a, ll b) {
  if (a >= 0)
    return (a + b - 1) / b;
  else
    return a / b;
}

int main(void) {
  ios::sync_with_stdio(false);
  int l, n;
  cin >> n >> l;
  vector<TEvent> events(n);
  for (auto& ev: events) {
    cin >> ev.t >> ev.x >> ev.y;
  }
  ++n;
  events.push_back(TEvent());
  sort(events.begin(), events.end(), [l](const TEvent& left, const TEvent& right){ return left.t % l < right.t % l; });
  bool collision_found = false;
  ll total_dx = 0, total_dy = 0;
  ll min_sum = -INF, max_sum = INF, min_diff = -INF, max_diff = INF;
  for (int i = 0; i < n; ++i) {
    int im1 = i ? (i - 1) : (n - 1);
    ll dt = events[i].t - events[im1].t;
    ll dx = events[i].x - events[im1].x;
    ll dy = events[i].y - events[im1].y;
    if (dt < 0) {
      dt *= -1;
      dx *= -1;
      dy *= -1;
    }
    if (abs(dx) + abs(dy) > dt) {
      cout << "NO" << endl;
      return 0;
    }
    ll d_low_cycles = lbdiv(dt, l);
    ll d_high_cycles = ubdiv(dt, l);
    ll low_spread = dt - l * d_low_cycles;
    ll high_spread = l * d_high_cycles - dt;
    if (d_low_cycles != 0) {
      assign_max(min_sum, ubdiv(dx + dy - low_spread, d_low_cycles));
      assign_min(max_sum, lbdiv(dx + dy + low_spread, d_low_cycles));
      assign_max(min_diff, ubdiv(dx - dy - low_spread, d_low_cycles));
      assign_min(max_diff, lbdiv(dx - dy + low_spread, d_low_cycles));
    }
    if (d_high_cycles != 0) {
      assign_max(min_sum, ubdiv(dx + dy - high_spread, d_high_cycles));
      assign_min(max_sum, lbdiv(dx + dy + high_spread, d_high_cycles));
      assign_max(min_diff, ubdiv(dx - dy - high_spread, d_high_cycles));
      assign_min(max_diff, lbdiv(dx - dy + high_spread, d_high_cycles));
    }
  }
  if ((min_sum + l) % 2 != 0)
    ++min_sum;
  if ((min_diff + l) % 2 != 0)
    ++min_diff;
  if ((max_sum + l) % 2 != 0)
    --max_sum;
  if ((max_diff + l) % 2 != 0)
    --max_diff;
  if (max_diff < min_diff || max_sum < min_sum) {
    cout << "NO" << endl;
    return 0;
  }
  ll actual_dx = (min_diff + min_sum) / 2;
  ll actual_dy = (min_sum - min_diff) / 2;
  for (auto& ev : events) {
    ll c = ev.t / l;
    ev.t %= l;
    ev.x -= c * actual_dx;
    ev.y -= c * actual_dy;
  }
  events.push_back(TEvent());
  events.back().t = l;
  events.back().x = actual_dx;
  events.back().y = actual_dy;
  ostringstream oss;
  ll cx = 0, cy = 0, ct = 0;
  for (const auto& ev : events) {
    for (; ct < ev.t; ++ct) {
      if (cx < ev.x) {
        ++cx;
        oss << 'R';
      }
      else if (cx > ev.x) {
        --cx;
        oss << 'L';
      }
      else if (cy > ev.y) {
        --cy;
        oss << 'D';
      }
      else {
        ++cy;
        oss << 'U';
      }
    }
    if (cx != ev.x || cy != ev.y) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << oss.str() << endl;
  return 0;
}