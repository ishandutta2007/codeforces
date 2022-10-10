#include <bits/stdc++.h>
typedef long long ll;
#define f first
#define s second

using namespace std;

const int sq = 350;

template<typename T>
struct modular_base{
	using Type = typename decay<decltype(T::value)>::type;
	static vector<Type> _MOD_INV;
	constexpr modular_base(): value(){ }
	template<typename U> modular_base(const U &x){ value = normalize(x); }
	template<typename U> static Type normalize(const U &x){
		Type v;
		if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
		else v = static_cast<Type>(x % mod());
		if(v < 0) v += mod();
		return v;
	}
	const Type& operator()() const{ return value; }
	template<typename U> explicit operator U() const{ return static_cast<U>(value); }
	constexpr static Type mod(){ return T::value; }
	modular_base &operator+=(const modular_base &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
	modular_base &operator-=(const modular_base &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
	template<typename U> modular_base &operator+=(const U &otr){ return *this += modular_base(otr); }
	template<typename U> modular_base &operator-=(const U &otr){ return *this -= modular_base(otr); }
	modular_base &operator++(){ return *this += 1; }
	modular_base &operator--(){ return *this -= 1; }
	modular_base operator++(int){ modular_base result(*this); *this += 1; return result; }
	modular_base operator--(int){ modular_base result(*this); *this -= 1; return result; }
	modular_base operator-() const{ return modular_base(-value); }
	template<typename U = T>
	typename enable_if<is_same<typename modular_base<U>::Type, int>::value, modular_base>::type &operator*=(const modular_base& rhs){
		#ifdef _WIN32
		unsigned long long x = static_cast<long long>(value) * static_cast<long long>(rhs.value);
		unsigned int xh = static_cast<unsigned int>(x >> 32), xl = static_cast<unsigned int>(x), d, m;
		asm(
			"divl %4; \n\t"
			: "=a" (d), "=d" (m)
			: "d" (xh), "a" (xl), "r" (mod())
		);
		value = m;
		#else
		value = normalize(static_cast<long long>(value) * static_cast<long long>(rhs.value));
		#endif
		return *this;
	}
	template<typename U = T>
	typename enable_if<is_same<typename modular_base<U>::Type, long long>::value, modular_base>::type &operator*=(const modular_base &rhs){
		long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template<typename U = T>
	typename enable_if<!is_integral<typename modular_base<U>::Type>::value, modular_base>::type &operator*=(const modular_base &rhs){
		value = normalize(value * rhs.value);
		return *this;
	}
	template<typename U>
	modular_base &operator^=(U e){
		if(e < 0) *this = 1 / *this, e = -e;
		modular_base res = 1;
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	template<typename U>
	modular_base operator^(U e) const{
		return modular_base(*this) ^= e;
	}
	modular_base &operator/=(const modular_base &otr){
		Type a = otr.value, m = mod(), u = 0, v = 1;
		if(a < (int)_MOD_INV.size()) return *this *= _MOD_INV[a];
		while(a){
			Type t = m / a;
			m -= t * a; swap(a, m);
			u -= t * v; swap(u, v);
		}
		assert(m == 1);
		return *this *= u;
	}
	Type value;
};
template<typename T> bool operator==(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const modular_base<T>& lhs, U rhs){ return lhs == modular_base<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) == rhs; }
template<typename T> bool operator!=(const modular_base<T> &lhs, const modular_base<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const modular_base<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const modular_base<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> modular_base<T> operator+(const modular_base<T> &lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator+(const modular_base<T> &lhs, U rhs){ return modular_base<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator+(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) += rhs; }
template<typename T> modular_base<T> operator-(const modular_base<T> &lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator-(const modular_base<T>& lhs, U rhs){ return modular_base<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator-(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) -= rhs; }
template<typename T> modular_base<T> operator*(const modular_base<T> &lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator*(const modular_base<T>& lhs, U rhs){ return modular_base<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator*(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) *= rhs; }
template<typename T> modular_base<T> operator/(const modular_base<T> &lhs, const modular_base<T> &rhs) { return modular_base<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator/(const modular_base<T>& lhs, U rhs) { return modular_base<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator/(U lhs, const modular_base<T> &rhs) { return modular_base<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, modular_base<T> &number){
	typename common_type<typename modular_base<T>::Type, long long>::type x;
	in >> x;
	number.value = modular_base<T>::normalize(x);
	return in;
}
template<typename T> ostream &operator<<(ostream &out, const modular_base<T> &number){ return out << number(); }
template<typename T> vector<typename modular_base<T>::Type> modular_base<T>::_MOD_INV;
template<typename T>
void precalc_inverse(int SZ){
	auto &inv = T::_MOD_INV;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((T::mod() - 1LL * T::mod() / (int)inv.size() * inv[T::mod() % (int)inv.size()]) % T::mod());
}
template<typename T>
vector<T> precalc_power(T base, int SZ){
	vector<T> res(SZ + 1, 1);
	for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
	return res;
}

using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using modular = modular_base<VarMod>;

template<typename T>
struct FenwickTree {
    int n;
    vector<T> bit;

    FenwickTree(int n): n(n), bit(n, 0) {};

    T qry(int x) {
        T ret = 0;
        for(x++; x > 0; x -= (x & -x)) {
            ret += bit[x - 1];
        }
        return ret;
    }

    T qry(int x, int y) {
        return qry(y) - qry(x - 1);
    }

    void upd(int x, T k) {
        for(x++; x <= n; x += (x & -x)) {
            bit[x - 1] += k;
        }
    }
};

int n, q, a[60000], val[60000], pos[60000], cur = -1, num[60000], lazy[(1 << 16)];
modular fibs[60002], seg1[1 << 16], seg2[1 << 16], ans[60000]; 
array<int, 2> ord[60000];
array<int, 4> qrs[60000];

modular get_fib(int ind) {
    if(ind < 0) {
        return ((ind & 1 ^ 1) ? -fibs[-ind] : fibs[-ind]);
    }
    return fibs[ind];
}

void push(int ind, int lo, int hi) {
    int delta = lazy[ind];
    modular cur_term = seg1[ind], pv_term = seg2[ind];
    seg1[ind] = get_fib(delta + 1) * cur_term + get_fib(delta) * pv_term;
    seg2[ind] = get_fib(delta) * cur_term + get_fib(delta - 1) * pv_term;
    if(lo != hi) {
        lazy[2 * ind + 1] += delta;
        lazy[2 * ind + 2] += delta;
    }
    lazy[ind] = 0;
}

void upd(int lo, int delta, int lo_ind, int hi_ind, int ind, bool on) {
    if(lazy[ind] != 0) {
        push(ind, lo_ind, hi_ind);
    }
    if(lo > hi_ind) {
        return;
    }
    if(lo < lo_ind) {
        lazy[ind] = (on ? 1 : -1);
        push(ind, lo_ind, hi_ind);
        return;
    }
    if(lo_ind == hi_ind) {
        seg1[ind] = get_fib(delta + 1) * (on ? val[lo_ind] : 0);
        seg2[ind] = get_fib(delta) * (on ? val[lo_ind] : 0);
        return;
    }
    int mid = (lo_ind + hi_ind) / 2;
    upd(lo, delta, lo_ind, mid, 2 * ind + 1, on);
    upd(lo, delta, mid + 1, hi_ind, 2 * ind + 2, on);
    seg1[ind] = seg1[2 * ind + 1] + seg1[2 * ind + 2];
    seg2[ind] = seg2[2 * ind + 1] + seg2[2 * ind + 2];
}

int main() {
    // auto begin = std::chrono::high_resolution_clock::now();
    // freopen("yuh.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> mod;
    FenwickTree<int> ft(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ord[i] = {a[i], i};
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> qrs[i][2] >> qrs[i][1];
        --qrs[i][2], --qrs[i][1];
        qrs[i][0] = qrs[i][2] / sq, qrs[i][3] = i;
    }
    sort(ord, ord + n);
    sort(qrs, qrs + q);
    for(int i = 0; i < n; i++) {
        if(i == 0 || ord[i][0] != ord[i - 1][0]) {
            val[++cur] = ord[i][0];
        }
        pos[ord[i][1]] = cur;
    }
    fibs[1] = 1;
    for(int i = 2; i <= n + 1; i++) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
    n = cur;
    for(int i = 0, l = 0, r = -1; i < q; i++) {
        int left_point = qrs[i][2], right_point = qrs[i][1], ind;
        while(l > left_point) {
            --l, ind = pos[l];
            if(num[ind] == 0) {
                upd(ind, ft.qry(pos[l]), 0, (1 << 15) - 1, 0, true);
                ft.upd(ind, 1);
            }
            ++num[ind];
        }
        while(r < right_point) {
            ++r, ind = pos[r];
            if(num[ind] == 0) {
                upd(ind, ft.qry(ind), 0, (1 << 15) - 1, 0, true);
                ft.upd(ind, 1);
            }
            ++num[ind];
        }
        while(l < left_point) {
            ind = pos[l], --num[ind];
            if(num[ind] == 0) {
                upd(ind, 0, 0, (1 << 15) - 1, 0, false);
                ft.upd(ind, -1);
            }
            ++l;
        }
        while(r > right_point) {
            ind = pos[r], --num[ind];
            if(num[ind] == 0) {
                upd(ind, 0, 0, (1 << 15) - 1, 0, false);
                ft.upd(ind, -1);
            }
            --r;
        }
        ans[qrs[i][3]] = seg1[0];
    }
    for(int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
    // auto end = std::chrono::high_resolution_clock::now();
    // cout << setprecision(4) << fixed;
    // cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
}