#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif

// ModInt source: https://github.com/the-tourist/algo/blob/master/numeric/mint.cpp
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
	T t = m / a;
	m -= t * a; swap(a, m);
	u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
	value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
	Type v;
	if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
	else v = static_cast<Type>(x % mod());
	if (v < 0) v += mod();
	return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
	uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
	asm(
	  "divl %4; \n\t"
	  : "=a" (d), "=d" (m)
	  : "d" (xh), "a" (xl), "r" (mod())
	);
	value = m;
#else
	value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
	return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
	int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
	value = normalize(value * rhs.value - q * mod());
	return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
	value = normalize(value * rhs.value);
	return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
	if (p & 1) res *= x;
	x *= x;
	p >>= 1;
  }
  return res;
}

template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int md = 998244353;
using mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin>>t;
	while(t--){
		int n, m;  cin >> n >> m;
		vector<vector<int>> adj(n), rdj(n);
		vector<int> a(n);
		vector<mint> f(n);

		for(int& x: a) cin >> x;

		vector<int> deg(n);
		for(int i = 0; i < m; i++){
			int u, v; cin >> u >> v;
			u--; v--;
			adj[u].push_back(v);
			rdj[v].push_back(u);
			deg[v]++;
		}
		set<pair<int, int>> S;
		for(int i = 0; i < n; i++) S.insert({deg[i], i});
		const int INF = 1 << 20;
		vector<int> dist(n, INF);
		vector<int> nodes;
		while(!S.empty()){
			// trace(S);
			int u = S.begin()->second;
			nodes.push_back(u);
			S.erase({deg[u], u});
			for(int v: adj[u]){
				S.erase({deg[v], v});
				deg[v]--;
				S.insert({deg[v], v});
			}
		}

		for(int i = 0; i <= n; i++){
			if(*max_element(all(a)) == 0){
				cout << i << endl;
				goto nextiter;
			}
			vector<bool> process(n);
			for(int u: nodes) process[u] = a[u] > 0;
			for(int u: nodes) if(process[u]){
				a[u]--;
				for(int v: adj[u]) a[v]++;
			}
		}
		for(int u: nodes){
			if(a[u] > 0) dist[u] = 0;
			for(int v: rdj[u]) if(dist[v] != INF){
				dist[u] = min(dist[u], dist[v] + 1);
				f[u] += f[v] - dist[v];
			}
			if(dist[u] == INF) continue;
			f[u] += dist[u] + a[u];
		}
		
		cout << (n + 1 + f[nodes.back()]) << endl;
		nextiter: continue;
	}
}