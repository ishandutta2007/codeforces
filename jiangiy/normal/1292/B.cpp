#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int,int> pii;

const int base = 1000000000; 
const int base_digits = 9; 
struct bigint{ 
	vector < int > z; 
	int sign; 
	bigint() : sign(1) {} 
	bigint(long long v) {* this = v; 
	} 
	bigint(const string & s) { 
		read(s); 
	} 
	void operator = (const bigint & v) { 
		sign = v.sign; 
		z = v.z; 
	} 
	void operator = (long long v) { 
		sign = 1; 
		if (v < 0) sign =- 1, v =- v; 
		z.clear(); 
		for (; v > 0; v = v / base) z.push_back(v % base); 
	} 
	bigint operator + (const bigint & v) const{ 
		if (sign == v.sign) { 
			bigint res = v; 
			for (int i = 0, carry = 0; i < (int) max(z.size(), v.z.size()) || carry; ++ i) { 
				if (i == (int) res.z.size()) res.z.push_back(0); 
				res.z[i] += carry + (i < (int) z.size() ? z[i] : 0); 
				carry = res.z[i] >= base; 
				if (carry) res.z[i] -= base; 
			} 
			return res; 
		} 
		return * this - (- v); 
	} 
	bigint operator - (const bigint & v) const{ 
		if (sign == v.sign) { 
			if (abs() >= v.abs()) { 
				bigint res =* this; 
				for (int i = 0, carry = 0; i < (int) v.z.size() || carry; ++ i) { 
					res.z[i] -= carry + (i < (int) v.z.size() ? v.z[i] : 0); 
					carry = res.z[i] < 0; 
					if (carry) res.z[i] += base; 
				} 
				res.trim(); 
				return res; 
			} 
			return - (v -* this); 
		} 
		return * this + (- v); 
	} 
	void operator *= (int v) { 
		if (v < 0) sign =- sign, v =- v; 
		for (int i = 0, carry = 0; i < (int) z.size() || carry; ++ i) { 
			if (i == (int) z.size()) z.push_back(0); 
			long long cur = z[i] * (long long) v + carry; 
			carry = (int)(cur / base); 
			z[i] = (int)(cur % base); 
		} 
		trim(); 
	} 
	bigint operator * (int v) const{ 
		bigint res =* this; 
		res *= v; 
		return res; 
	} 
	friend pair < bigint, bigint > divmod(const bigint & a1, const bigint & b1) { 
		int norm = base / (b1.z.back() + 1); 
		bigint a = a1.abs() * norm; 
		bigint b = b1.abs() * norm; 
		bigint q, r; 
		q.z.resize(a.z.size()); 
		for (int i = a.z.size() - 1; i >= 0; i --) { 
			r *= base; 
			r += a.z[i]; 
			int s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0; 
			int s2 = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0; 
			int d = ((long long) s1 * base + s2) / b.z.back(); 
			r -= b * d; 
			while (r < 0) r += b, -- d; 
			q.z[i] = d; 
		} 
		q.sign = a1.sign * b1.sign; 
		r.sign = a1.sign; 
		q.trim(); 
		r.trim(); 
		return make_pair(q, r / norm); 
	} 
	friend bigint sqrt(const bigint & a1) { 
		bigint a = a1; 
		while (a.z.empty() || a.z.size() % 2 == 1) a.z.push_back(0); 
		int n = a.z.size(); 
		int firstDigit = (int) sqrt((double) a.z[n - 1] * base + a.z[n - 2]); 
		int norm = base / (firstDigit + 1); 
		a *= norm; 
		a *= norm; 
		while (a.z.empty() || a.z.size() % 2 == 1) a.z.push_back(0); 
		bigint r = (long long) a.z[n - 1] * base + a.z[n - 2]; 
		firstDigit = (int) sqrt((double) a.z[n - 1] * base + a.z[n - 2]); 
		int q = firstDigit; 
		bigint res; 
		for (int j = n / 2 - 1; j >= 0; j --) { 
			for (;; -- q) { 
				bigint r1 = (r - (res * 2 * base + q) * q) * base * base + (j > 0 ? (long long) a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0); 
				if (r1 >= 0) { 
					r = r1; 
					break; 
				} 
			} 
			res *= base; 
			res += q; 
			if (j > 0) { 
				int d1 = res.z.size() + 2 < r.z.size() ? r.z[res.z.size() + 2] : 0; 
				int d2 = res.z.size() + 1 < r.z.size() ? r.z[res.z.size() + 1] : 0; 
				int d3 = res.z.size() < r.z.size() ? r.z[res.z.size()] : 0; 
				q = ((long long) d1 * base * base + (long long) d2 * base + d3) / (firstDigit * 2); 
			} 
		} 
		res.trim(); 
		return res / norm; 
	} 
	bigint operator / (const bigint & v) const{ 
		return divmod(* this, v).first; 
	} 
	bigint operator % (const bigint & v) const{ 
		return divmod(* this, v).second; 
	} 
	void operator /= (int v) { 
		if (v < 0) sign =- sign, v =- v; 
		for (int i = (int) z.size() - 1, rem = 0; i >= 0; -- i) { 
			long long cur = z[i] + rem * (long long) base; 
			z[i] = (int)(cur / v); 
			rem = (int)(cur % v); 
		} 
		trim(); 
	} 
	bigint operator / (int v) const{ 
		bigint res =* this; 
		res /= v; 
		return res; 
	} 
	int operator % (int v) const{ 
		if (v < 0) v =- v; 
		int m = 0; 
		for (int i = z.size() - 1; i >= 0; -- i) m = (z[i] + m * (long long) base) % v; 
		return m * sign; 
	} 
	void operator += (const bigint & v) {* this =* this + v; 
	} 
	void operator -= (const bigint & v) {* this =* this - v; 
	} 
	void operator *= (const bigint & v) {* this =* this * v; 
	} 
	void operator /= (const bigint & v) {* this =* this / v; 
	} 
	bool operator < (const bigint & v) const{ 
		if (sign != v.sign) return sign < v.sign; 
		if (z.size() != v.z.size()) return z.size() * sign < v.z.size() * v.sign; 
		for (int i = z.size() - 1; i >= 0; i --) if (z[i] != v.z[i]) return z[i] * sign < v.z[i] * sign; 
		return false; 
	} 
	bool operator > (const bigint & v) const{ 
		return v <* this; 
	} 
	bool operator <= (const bigint & v) const{ 
		return ! (v <* this); 
	} 
	bool operator >= (const bigint & v) const{ 
		return ! (* this < v); 
	} 
	bool operator == (const bigint & v) const{ 
		return ! (* this < v) &&! (v <* this); 
	} 
	bool operator != (const bigint & v) const{ 
		return * this < v || v <* this; 
	} 
	void trim() { 
		while (! z.empty() && z.back() == 0) z.pop_back(); 
		if (z.empty()) sign = 1; 
	} 
	bool isZero() const{ 
		return z.empty() || (z.size() == 1 &&! z[0]); 
	} 
	bigint operator - () const{ 
		bigint res =* this; 
		res.sign =- sign; 
		return res; 
	} 
	bigint abs() const{ 
		bigint res =* this; 
		res.sign *= res.sign; 
		return res; 
	} 
	long long longValue() const{ 
		long long res = 0; 
		for (int i = z.size() - 1; i >= 0; i --) res = res * base + z[i]; 
		return res * sign; 
	} 
	friend bigint __gcd(const bigint & a, const bigint & b) { 
		return b.isZero() ? a : __gcd(b, a % b); 
	} 
	friend bigint lcm(const bigint & a, const bigint & b) { 
		return a / __gcd(a, b) * b; 
	} 
	void read(const string & s) { 
		sign = 1; 
		z.clear(); 
		int pos = 0; 
		while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) { 
			if (s[pos] == '-') sign =- sign; 
			++ pos; 
		} 
		for (int i = s.size() - 1; i >= pos; i -= base_digits) { 
			int x = 0; 
			for (int j = max(pos, i - base_digits + 1); j <= i; j ++) x = x * 10 + s[j] - '0'; 
			z.push_back(x); 
		} 
		trim(); 
	} 
	friend istream & operator >> (istream & stream, bigint & v) { 
		string s; 
		stream >> s; 
		v.read(s); 
		return stream; 
	} 
	friend ostream & operator << (ostream & stream, const bigint & v) { 
		if (v.sign ==- 1) stream << '-'; 
		stream << (v.z.empty() ? 0 : v.z.back()); 
		for (int i = (int) v.z.size() - 2; i >= 0; -- i) stream << setw(base_digits) << setfill('0') << v.z[i]; 
		return stream; 
	} 
	static vector < int > convert_base(const vector < int >& a, int old_digits, int new_digits) { 
		vector < long long > p(max(old_digits, new_digits) + 1); 
		p[0] = 1; 
		for (int i = 1; i < (int) p.size(); i ++) p[i] = p[i - 1] * 10; 
		vector < int > res; 
		long long cur = 0; 
		int cur_digits = 0; 
		for (int i = 0; i < (int) a.size(); i ++) { 
			cur += a[i] * p[cur_digits]; 
			cur_digits += old_digits; 
			while (cur_digits >= new_digits) { 
				res.push_back(int(cur % p[new_digits])); 
				cur /= p[new_digits]; 
				cur_digits -= new_digits; 
			} 
		} 
		res.push_back((int) cur); 
		while (! res.empty() && res.back() == 0) res.pop_back(); 
		return res; 
	} 
	typedef vector < long long > vll; 
	static vll karatsubaMultiply(const vll & a, const vll & b) { 
		int n = a.size(); 
		vll res(n + n); 
		if (n <= 32) { 
			for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) res[i + j] += a[i] * b[j]; 
			return res; 
		} 
		int k = n >> 1; 
		vll a1(a.begin(), a.begin() + k); 
		vll a2(a.begin() + k, a.end()); 
		vll b1(b.begin(), b.begin() + k); 
		vll b2(b.begin() + k, b.end()); 
		vll a1b1 = karatsubaMultiply(a1, b1); 
		vll a2b2 = karatsubaMultiply(a2, b2); 
		for (int i = 0; i < k; i ++) a2[i] += a1[i]; 
		for (int i = 0; i < k; i ++) b2[i] += b1[i]; 
		vll r = karatsubaMultiply(a2, b2); 
		for (int i = 0; i < (int) a1b1.size(); i ++) r[i] -= a1b1[i]; 
		for (int i = 0; i < (int) a2b2.size(); i ++) r[i] -= a2b2[i]; 
		for (int i = 0; i < (int) r.size(); i ++) res[i + k] += r[i]; 
		for (int i = 0; i < (int) a1b1.size(); i ++) res[i] += a1b1[i]; 
		for (int i = 0; i < (int) a2b2.size(); i ++) res[i + n] += a2b2[i]; 
		return res; 
	} 
	bigint operator * (const bigint & v) const{ 
		vector < int > a6 = convert_base(this->z, base_digits, 6); 
		vector < int > b6 = convert_base(v.z, base_digits, 6); 
		vll a(a6.begin(), a6.end()); 
		vll b(b6.begin(), b6.end()); 
		while (a.size() < b.size()) a.push_back(0); 
		while (b.size() < a.size()) b.push_back(0); 
		while (a.size() & (a.size() - 1)) a.push_back(0), b.push_back(0); 
		vll c = karatsubaMultiply(a, b); 
		bigint res; 
		res.sign = sign * v.sign; 
		for (int i = 0, carry = 0; i < (int) c.size(); i ++) { 
			long long cur = c[i] + carry; 
			res.z.push_back((int)(cur % 1000000)); 
			carry = (int)(cur / 1000000); 
		} 
		res.z = convert_base(res.z, 6, base_digits); 
		res.trim(); 
		return res; 
	} 
}
; 
bigint abs(bigint x) { 
	return x < 0 ?- x : x; 
} 
ll x[100], y[100], ax, ay, bx, by, xs, ys, t; 
int c; 
void solve() { 
	int ans = 0; 
	for (int i = 0; i <= c; i ++) { 
		ll tx = xs, ty = ys, l = 0; 
		for (int j = i; j <= c; j ++) { 
			l += abs(x[j] - tx) + abs(y[j] - ty); 
			tx = x[j], ty = y[j]; 
			if (l > t) break; 
			ans = max(ans, j - i + 1); 
			ll tx2 = tx, ty2 = ty, l2 = l; 
			for (int k = i - 1; k >= 0; k --) { 
				l2 += abs(x[k] - tx2) + abs(y[k] - ty2); 
				tx2 = x[k], ty2 = y[k]; 
				if (l2 > t) break; 
				ans = max(ans, j - i + 1 + i - k); 
			} 
		} 
		tx = xs, ty = ys, l = 0; 
		for (int j = i; j >= 0; j --) { 
			l += abs(x[j] - tx) + abs(y[j] - ty); 
			tx = x[j], ty = y[j]; 
			if (l > t) break; 
			ans = max(ans, i - j + 1); 
			ll tx2 = tx, ty2 = ty, l2 = l; 
			for (int k = i + 1; k <= c; k ++) { 
				l2 += abs(x[k] - tx2) + abs(y[k] - ty2); 
				tx2 = x[k], ty2 = y[k]; 
				if (l2 > t) break; 
				ans = max(ans, i - j + 1 + k - i); 
			} 
		} 
	} 
	cout << ans << endl; 
} 
int main() { 
	bigint x[100], y[100], ax, ay, bx, by, xs, ys, t; 
	cin >> x[0] >> y[0] >> ax >> ay >> bx >> by >> xs >> ys >> t; 
	while (c < 90) { 
		x[c + 1] = x[c] * ax + bx; 
		y[c + 1] = y[c] * ay + by; 
		c ++; 
	} 
	while (c >= 0 && abs(x[c] - xs) + abs(y[c] - ys) > t) c --; 
	if (c ==- 1) { 
		return puts("0"), 0; 
	} 
	for (int i = 0; i <= c; i ++)::x[i] = x[i].longValue(),::y[i] = y[i].longValue();::ax = ax.longValue(),::ay = ay.longValue(),::bx = bx.longValue(),::by = by.longValue(),::xs = xs.longValue(),::ys = ys.longValue(),::t = t.longValue(); 
	solve(); 
}