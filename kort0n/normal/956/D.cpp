#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
struct SegmentTree {
private:
    int n;
    vector<ll> node;
 
public:
    SegmentTree() {
        int sz = 100050;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
 
    void add(int x, ll val) {
        x += (n - 1);
        node[x] += val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = (node[2*x+1] + node[2*x+2]);
        }
    }
    // hannkaikukann 
    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return (vl + vr);
    }
};

struct rational {
  ll p, q;
  void normalize() { // keep q positive
    if (q < 0) p *= -1, q *= -1;
    ll d = __gcd(p < 0 ? -p : p, q);
    if (d == 0) p = 0,  q = 1;
    else        p /= d, q /= d;
  }
  rational(ll p, ll q = 1) : p(p), q(q) {
    normalize();
  }
  rational &operator += (const rational &a) {
    p = a.q * p + a.p * q; q = a.q * q; normalize();
    return *this;
  }
  rational &operator -= (const rational &a) {
    p = a.q * p - a.p * q; q = a.q * q; normalize();
    return *this;
  }
  rational &operator *= (const rational &a) {
    p *= a.p; q *= a.q; normalize();
    return *this;
  }
  rational &operator /= (const rational &a) {
    p *= a.q; q *= a.p; normalize();
    return *this;
  }
  rational &operator - () {
    p *= -1;
    return *this;
  }
};
rational operator + (const rational &a, const rational &b) {
  return rational(a) += b;
}
rational operator * (const rational &a, const rational &b) {
  return rational(a) *= b;
}
rational operator - (const rational &a, const rational &b) {
  return rational(a) -= b;
}
rational operator / (const rational &a, const rational &b) {
  return rational(a) /= b;
}
bool operator < (const rational &a, const rational &b) { // avoid overflow
  return (long double) a.p * b.q < (long double) a.q * b.p;
}
bool operator <= (const rational &a, const rational &b) {
  return !(b < a);
}
bool operator > (const rational &a, const rational &b) {
  return b < a;
}
bool operator >= (const rational &a, const rational &b) {
  return !(a < b);
}
bool operator == (const rational &a, const rational &b) {
  return !(a < b) && !(b < a);
}
bool operator != (const rational &a, const rational &b) {
  return (a < b) || (b < a);
}
rational abs(rational in) {
  rational ret = in;
  ret.p = abs(ret.p);
  ret.q = abs(ret.q);
  return ret;
}


int main() {
    ll N, w;
    cin >> N >> w;
    vector<ll> x(N), v(N);
    map<ll, ll> initial;
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> v[i];
        initial[x[i]]++;
    }
    ll ans = N * (N - 1) / 2;
    for(auto tmp : initial) {
        ll num = tmp.second;
        ans -= num * (num - 1) / 2;
    }
    vector<rational> Rational;
    for(int i = 0; i < N; i++) {
        Rational.emplace_back(w + v[i], x[i]);
    }
    sort(Rational.begin(), Rational.end());
    Rational.erase(unique(Rational.begin(), Rational.end()), Rational.end());
    map<ll, vector<ll>> mp[2];
    for(int i = 0; i < N; i++) {
        rational r(w+v[i], x[i]);
        auto itr = lower_bound(Rational.begin(), Rational.end(), r);
        int idx = distance(Rational.begin(), itr);
        //cerr << i << " " << r.p << " " << r.q << " " << idx << endl;
        if(x[i] > 0) mp[1][x[i]].push_back(idx);
        else mp[0][x[i]].push_back(idx);
    }
    SegmentTree seg[2];
    for(auto X : mp[0]) {
        for(auto tmp : X.second) {
            ans -= seg[0].getsum(0, tmp);
        }
        for(auto tmp : X.second) {
            seg[0].add(tmp, 1);
        }
    }
    cerr << ans << endl;
    for(auto X : mp[1]) {
        for(auto tmp : X.second) {
            ans -= seg[1].getsum(0, tmp);
            ans -= seg[0].getsum(tmp + 1, N);
        }
        for(auto tmp : X.second) {
            seg[1].add(tmp, 1);
        }
    }
    cerr << ans << endl;
    Rational.clear();
    for(int i = 0; i < N; i++) {
        Rational.emplace_back(-w + v[i], x[i]);
    }
    sort(Rational.begin(), Rational.end());
    Rational.erase(unique(Rational.begin(), Rational.end()), Rational.end());
    mp[0].clear();
    mp[1].clear();
    for(int i = 0; i < N; i++) {
        rational r(-w+v[i], x[i]);
        auto itr = lower_bound(Rational.begin(), Rational.end(), r);
        int idx = distance(Rational.begin(), itr);
        //cerr << i << " " << r.p << " " << r.q << " " << idx << endl;
        if(x[i] > 0) mp[1][x[i]].push_back(idx);
        else mp[0][x[i]].push_back(idx);
    }
    seg[0] = SegmentTree();
    seg[1] = SegmentTree();
    for(auto X : mp[0]) {
        for(auto tmp : X.second) {
            ans -= seg[0].getsum(tmp+1, N);
        }
        for(auto tmp : X.second) {
            seg[0].add(tmp, 1);
        }
    }
    cerr << ans << endl;
    for(auto X : mp[1]) {
        for(auto tmp : X.second) {
            ans -= seg[1].getsum(tmp+1, N);
            ans -= seg[0].getsum(0, tmp);
        }
        for(auto tmp : X.second) {
            seg[1].add(tmp, 1);
        }
    }
    cout << ans << endl;
    return 0;
}