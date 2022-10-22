#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n;

// --------------

struct BigInteger {
  typedef unsigned long long LL;

  static const int BASE = 100000000;
  static const int WIDTH = 8;
  vector<int> s;

  BigInteger& clean(){while(!s.back()&&s.size()>1)s.pop_back(); return *this;}
  BigInteger(LL num = 0) {*this = num;}
  BigInteger(string s) {*this = s;}
  BigInteger& operator = (long long num) {
    s.clear();
    do {
      s.push_back(num % BASE);
      num /= BASE;
    } while (num > 0);
    return *this;
  }
  BigInteger& operator = (const string& str) {
    s.clear();
    int x, len = (str.length() - 1) / WIDTH + 1;
    for (int i = 0; i < len; i++) {
      int end = str.length() - i*WIDTH;
      int start = max(0, end - WIDTH);
      sscanf(str.substr(start,end-start).c_str(), "%d", &x);
      s.push_back(x);
    }
    return (*this).clean();
  }

  BigInteger operator + (const BigInteger& b) const {
    BigInteger c; c.s.clear();
    for (int i = 0, g = 0; ; i++) {
      if (g == 0 && i >= (int) s.size() && i >= (int) b.s.size()) break;
      int x = g;
      if (i < (int) s.size()) x += s[i];
      if (i < (int) b.s.size()) x += b.s[i];
      c.s.push_back(x % BASE);
      g = x / BASE;
    }
    return c;
  }
  BigInteger operator - (const BigInteger& b) const {
    assert(b <= *this);
    BigInteger c; c.s.clear();
    for (int i = 0, g = 0; ; i++) {
      if (g == 0 && i >= s.size() && i >= b.s.size()) break;
      int x = s[i] + g;
      if (i < b.s.size()) x -= b.s[i];
      if (x < 0) {g = -1; x += BASE;} else g = 0;
      c.s.push_back(x);
    }
    return c.clean();
  }
  BigInteger operator * (const BigInteger& b) const {
    int i, j; LL g;
    vector<LL> v(s.size()+b.s.size(), 0);
    BigInteger c; c.s.clear();
    for(i=0;i<s.size();i++) for(j=0;j<b.s.size();j++) v[i+j]+=LL(s[i])*b.s[j];
    for (i = 0, g = 0; ; i++) {
      if (g ==0 && i >= v.size()) break;
      LL x = v[i] + g;
      c.s.push_back(x % BASE);
      g = x / BASE;
    }
    return c.clean();
  }
  BigInteger operator / (const BigInteger& b) const {
    assert(b > 0);
    BigInteger c = *this;
    BigInteger m;
    for (int i = s.size()-1; i >= 0; i--) {
      m = m*BASE + s[i];
      c.s[i] = bsearch(b, m);
      m -= b*c.s[i];
    }
    return c.clean();
  }
  BigInteger operator % (const BigInteger& b) const {
    BigInteger c = *this;
    BigInteger m;
    for (int i = s.size()-1; i >= 0; i--) {
      m = m*BASE + s[i];
      c.s[i] = bsearch(b, m);
      m -= b*c.s[i];
    }
    return m;
  }

  int bsearch(const BigInteger& b, const BigInteger& m) const{
    int L = 0, R = BASE-1, x;
    while (1) {
      x = (L+R)>>1;
      if (b*x<=m) {if (b*(x+1)>m) return x; else L = x;}
      else R = x;
    }
  }

  BigInteger& operator += (const BigInteger& b) {*this = *this + b; return *this;}
  BigInteger& operator -= (const BigInteger& b) {*this = *this - b; return *this;}
  BigInteger& operator *= (const BigInteger& b) {*this = *this * b; return *this;}
  BigInteger& operator /= (const BigInteger& b) {*this = *this / b; return *this;}
  BigInteger& operator %= (const BigInteger& b) {*this = *this % b; return *this;}

  bool operator < (const BigInteger& b) const {
    if (s.size() != b.s.size()) return s.size() < b.s.size();
    for (int i = s.size()-1; i >= 0; i--)
      if (s[i] != b.s[i]) return s[i] < b.s[i];
    return false;
  }

  bool operator >(const BigInteger& b) const{return b < *this;}
  bool operator<=(const BigInteger& b) const{return !(b < *this);}
  bool operator>=(const BigInteger& b) const{return !(*this < b);}
  bool operator!=(const BigInteger& b) const{return b < *this || *this < b;}
  bool operator==(const BigInteger& b) const{return !(b < *this) && !(b > *this);}
};

ostream& operator << (ostream& out, const BigInteger& x) {
  out << x.s.back();
  for (int i = x.s.size()-2; i >= 0; i--) {
    char buf[20];
    memset(buf, 0, sizeof buf);
    sprintf(buf, "%08d", x.s[i]);
    for (int j = 0; j < strlen(buf); j++) out << buf[j];
  }
  return out;
}

istream& operator >> (istream& in, BigInteger& x) {
  string s;
  if (!(in >> s)) return in;
  x = s;
  return in;
}

// --------- Biginteger

string str, s1, s2;
BigInteger A, x, y, tmp, ans;

void getstr(int pos) {
  s1 = str.substr(0, pos);
  s2 = str.substr(pos, n);
  x = s1, y = s2, tmp = x + y;
}

void solve() {
  int mid = n / 2 + (n & 1);
  int l = mid, r = mid;
  while (l > 1 && str[l - 1] == '0') l--;
  while (r < n && str[r] == '0') r++;
  if (l > 1 && r == n) {
    getstr(l - 1);
    ans = tmp;
  } else if (r < n && l == 1) {
    getstr(r);
    ans = tmp;
  } else {
    getstr(l - 1);
    ans = tmp;
    getstr(r);
    if (!(ans < tmp)) ans = tmp;
  }
}

int main() {
  cin >> n >> str;
  A = str;
  solve();
  cout << ans;
  return 0;
}