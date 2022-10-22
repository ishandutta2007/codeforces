#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
  double x, y;
  point() {}
  point(double x_, double y_) : x(x_),y(y_) {}
  double len() {
    return sqrt(x*x+y*y);
  }
};
point operator-(const point& a, const point& b) {
  return {a.x-b.x, a.y-b.y};
}
point operator+(const point& a, const point& b) {
  return {a.x+b.x, a.y+b.y};
}
double operator*(const point& a, const point& b) {
  return a.x*b.x+a.y*b.y;
}
double operator%(const point& a, const point& b) {
  return a.x*b.y-a.y*b.x;
}
point operator*(const point& a, double f) {
  return {a.x*f, a.y*f};
}

struct Circle {
  point p;
  double r;
};

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define random erghergh
double random() {
  return 1.*mrand()/mrand.max();
}

point sampleCenter() {
  double x, y;
  do {
    x = random()*2e6-1e6;
    y = random()*2e6-1e6;
  } while (x*x+y*y > 1e6*1e6);
  return {x,y};
}

double pi = 3.141592653589793;

double circleDist(Circle a, Circle b) {
  double d = (a.p-b.p).len();
  double r1 = a.r, r2 = b.r;
  double dpp = abs(d+r1+r2);
  double dpm = abs(d+r1-r2);
  double dmp = abs(d-r1+r2);
  double dmm = abs(d-r1-r2);
  double haus = max({
      min(dmm,dmp),
	min(dpm,dpp),
	min(dmm,dpm),
	min(dmp,dpp)});
  return haus;
}

vector<point> genPoints(int n, int k, vector<Circle>&ans, int read = 0) {
  ans.resize(k);
  if (read) {
    for (int i = 0; i < k; i++) {
      cin >> ans[i].p.x >> ans[i].p.y >> ans[i].r;
    }
  } else {
    int ok = 0;
    while (!ok) {
      ok = 1;
      for (int i = 0; i < k; i++) {
	ans[i].p = sampleCenter();
	ans[i].r = random()*5e5+2.5e5;
	for (int j = 0; j < i; j++) {
	  if (circleDist(ans[i],ans[j]) < 6e5) ok = 0;
	}
      }
    }
  }
  vector<point> points;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      double theta = random()*pi*2;
      double r = (random()*0.2+0.9)*ans[i].r;
      points.push_back({cos(theta)*r+ans[i].p.x, sin(theta)*r+ans[i].p.y});
    }
  }
  //shuffle(points.begin(), points.end(), mrand());
  return points;
}

Circle findCircle(point a, point b, point c) {
  Circle r;
  r.p = (point(a.y-b.y,b.x-a.x)*((a-c)*(b-c)/((a-b)%(b-c)))+a+b)*0.5;
  r.r = (a-r.p).len();
  //cout << (a-r.p).len() << ' ' << (b-r.p).len() << ' ' << (c-r.p).len() << endl;
  return r;
}

Circle refineCircle1(Circle old, vector<point>&points, int plot = 0) {
  int n = points.size();
  vector<double> x, y, r;
  x.push_back(old.p.x);
  y.push_back(old.p.y);
  r.push_back(old.r);
  for (int it = 0; it < 100; it++) {
    int ai = mrand()%n;
    int bi = mrand()%n;
    int ci = mrand()%n;
    Circle c = findCircle(points[ai], points[bi], points[ci]);
    if (c.r > old.r*0.9 && c.r < old.r*1.1) {
      x.push_back(c.p.x);
      y.push_back(c.p.y);
      r.push_back(c.r);
    }
  }
  if (plot) {
    for (int i = 0; i < x.size(); i++) {
      cerr << x[i] << ' ' << y[i] << endl;
    }
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  sort(r.begin(), r.end());
  int k = x.size()/2;
  return {{x[k], y[k]}, r[k]};
}

Circle refineCircle(Circle old, vector<point>&points, int plot = 0) {
  int n = points.size();
  const int sections = 8;

  for (int it = 0; it < 100; it++) {
    vector<double> r;
    r.push_back(old.r);
    for (point p : points) {
      double rr = (p-old.p).len();
      if (rr > old.r*0.8 && rr < old.r*1.2)
	r.push_back(rr);
    }
    sort(r.begin(), r.end());
    old.r = r[r.size()/2];

    if (plot) {
      cerr << old.p.x << ' ' << old.p.y << endl;
    }

    vector<int> section(sections, 0);
    vector<point> pos(sections, {0,0});
    for (point p : points) {
      int i = sections*(atan2(p.y-old.p.y,p.x-old.p.x)+pi)/(2*pi);
      assert(i >= 0 && i < sections);
      point f = p-old.p;
      double r = f.len();
      if (r > old.r*0.8 && r < old.r*1.2) {
	f = f*((r > old.r ? 1. : -1)/r);
	pos[i] = (pos[i]*section[i]+f)*(1./(section[i]+1));
	section[i]++;
      }
    }
    point dp(0,0);
    for (int i = 0; i < sections; i++) {
      dp = dp+pos[i]*1e4;
      continue;
      double a = (i+0.5)/sections*2*pi-pi;
      point p = point(cos(a),sin(a))*old.r+old.p;
      //cout << sections*(atan2(p.y-old.p.y,p.x-old.p.x)+pi)/(2*pi)-i-0.5 << endl;
      if (section[i] == 0) {
	section[i]++;
	pos[i] = pos[i]+p;
      }
      /*if (plot) {
	cerr << p.x << ' ' << p.y << endl;
	}*/
    }
    if (dp.len() < 1e3) break;
    old.p = old.p+dp;
  }
  return old;
}

double scoreCircle2(Circle c, vector<point>&points, double tol) {
  int count = 0;
  vector<double> ang;
  for (int i = 0; i < points.size(); i++) {
    point d = points[i]-c.p;
    double r = d.len()/c.r;
    if (r > 1-tol && r < 1+tol) {
      count++;
      ang.push_back(atan2(d.y,d.x));
    }
  }
  ang.push_back(-pi);
  ang.push_back(pi);
  sort(ang.begin(), ang.end());
  double last = ang[0];
  double maxgap = 0;
  for (double d : ang) {
    maxgap = max(maxgap, d-last);
    last = d;
  }
  return maxgap;
}

int found[22][12];
int nx = 20, ny;

double scoreCircle(Circle c, vector<point>&points, double tol, int plot = 0) {
  for (int i = 0; i < nx; i++)
    for (int j = 0; j < ny; j++)
      found[i][j] = 0;

  int score = 0;
  for (int i = 0; i < points.size(); i++) {
    point d = points[i]-c.p;
    int x = nx*(atan2(d.y,d.x)+pi)/(2*pi);
    assert(x >= 0 && x < nx);
    double r = d.len()/c.r;
    if (r > 1-tol && r < 1+tol) {
      int y = (r-(1-tol))/(tol*2)*ny;
      assert(y >= 0 && y < ny);
      score += !(found[x][y]++);
    }
  }
  if (plot) {
    for (int x = 0; x < nx; x++) {
      for (int y = 0; y < ny; y++) {
	if (found[x][y]) {
	  double a = (x+0.5)/nx*2*pi-pi;
	  double r = c.r*((y+0.5)/ny*(2*tol)+(1-tol));
	  point p = point(cos(a),sin(a))*r+c.p;
	  cerr << p.x << ' ' << p.y << endl;
	}
      }
    }
  }
  return -score;
}

vector<point> filterCircle(Circle c, vector<point>&points, double tol) {
  vector<point> goods;
  for (int i = 0; i < points.size(); i++) {
    point d = points[i]-c.p;
    double r = d.len()/c.r;
    if (r > 1-tol && r < 1+tol) {
      goods.push_back(points[i]);
    }
  }
  return goods;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int trials = 0; trials < 10000*0+1; trials++) {
    //cout << trials << endl;
    int n = mrand()%901+100, k = mrand()%4+1;
    cin >> k >> n;

    nx = 20;
    ny = 3;
    vector<Circle> truth;
    vector<point> points(n*k);// = genPoints(n, k, truth);
    for (int i = 0; i < n*k; i++) {
      cin >> points[i].x >> points[i].y;
    }
    vector<pair<double,Circle>> cands;
    for (int it = 0; it < 100000; it++) {
      int ai = mrand()%(n*k);
      int bi = mrand()%(n*k);
      int ci = mrand()%(n*k);
      if (set<int>({ai,bi,ci}).size() < 3) continue;
      Circle c = findCircle(points[ai], points[bi], points[ci]);
      if (c.r > 7.5e5 || c.r < 2.5e5) continue;

      //vector<point> goods = filterCircle(p, a);
      //c = refineCircle(c, goods);
      //auto pb = scoreCircle(c, points, 0.1);
      double maxgap = scoreCircle(c, points, 0.1);
      //if (pb.second.size() >= n*0.9)
      cands.push_back({-maxgap,c});
      //cerr << c.p.x << ' ' << c.p.y << endl;
    }
    sort(cands.begin(), cands.end(), [](pair<double,Circle> a, pair<double,Circle> b) {return a.first > b.first;});
    vector<Circle> ans;
    for (auto pa : cands) {
      Circle a = pa.second;
      int ok = 1;
      for (Circle b : ans) {
	if (circleDist(a,b) < 5.5e5) ok = 0;
      }
      if (ok == 1) {
	ans.push_back(a);
	if ((int)ans.size() == k) break;
      }
    }
    if ((int)ans.size() < k) {
      cout << "Only found " << ans.size() << " circles" << endl;
      return 0;
    }

    vector<Circle> backup = ans;
    for (Circle&c : ans) {
      auto goods = filterCircle(c, points, 0.2);
      c = refineCircle(c, goods);
    }

    cout << setprecision(20);
    for (Circle c : ans) {
      cout << c.p.x << ' ' << c.p.y << ' ' << c.r << endl;
    }

    if (0) {
      int ok = 0;
      for (int i = 0; i < k; i++) {
	double min_dist = 1e9;
	double mini = -1;
	for (int j = 0; j < k; j++) {
	  double haus = circleDist(truth[i], ans[j]);
	  if (haus < min_dist) {
	    min_dist = haus;
	    mini = j;
	  }
	}
	if (min_dist > 1e5) {
	  cout << min_dist/1e5 << endl;
	  cout << scoreCircle(truth[i], points, 0.1) << ' ' << scoreCircle(backup[mini], points, 0.1) << ' ' << scoreCircle(ans[mini], points, 0.1) << endl;
	} else ok++;
      }
      if (ok != k) {
	cout << "Failed" << endl;
	for (point p : points) {
	  cerr << p.x << ' ' << p.y << endl;
	}
	cerr << endl << endl;
	for (Circle c : ans) {
	  cout << "Score: " << scoreCircle(c, points, 0.1, 1) << endl;
	  auto goods = filterCircle(c, points, 0.2);
	  refineCircle(c, goods, 1);
	  cerr << c.p.x << ' ' << c.p.y << ' ' << endl;
	  for (int i = 0; i < 100; i++) {
	    double a = i*pi*2/100;
	    cerr << c.p.x+c.r*cos(a) << ' ' << c.p.y+c.r*sin(a) << endl;
	  }
	}
	cerr << endl << endl;
	for (Circle c : truth) {
	  cout << "Score: " << scoreCircle(c, points, 0.1) << endl;
	  cerr << c.p.x << ' ' << c.p.y << ' ' << endl;
	}
	return 0;
      }
    }
  }
}