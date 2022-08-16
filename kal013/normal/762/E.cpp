/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 

/*/---------------------------IO(Debugging)----------------------/*/
template<class T> istream& operator >> (istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
template<class T, size_t N> istream& operator >> (istream &is, array<T, N>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 const& value){
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) 
        os << '-';
    else if (T == 0)
        return os << '0';
    for(; T > 0; ++index){
        buffer[index] = static_cast<char>('0' + (T % 10));
        T /= 10;
    }    
    while(index > 0)
        os << buffer[--index];
    return os;
}
istream& operator >> (istream& is, __int128& T){
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-')
        ++index, mul *= -1;
    for(; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;    
    return is;
}
#endif
template<typename CharT, typename Traits, typename T>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, T const &val) {
    return (out << val << " ");
}
template<typename CharT, typename Traits, typename T1, typename T2>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, pair<T1, T2> const &val) {
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename CharT, typename Traits, template<typename, typename...> class TT, typename... Args>
ostream& operator << (std::basic_ostream<CharT, Traits> &out, TT<Args...> const &cont) {
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");
}
template<class L, class R> ostream& operator << (ostream& out, pair<L, R> const &val){
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename L, size_t N> ostream& operator << (ostream& out, array<L, N> const &cont){
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");    
}
template<class T> ostream& operator<<(ostream &out, ordered_set<T> const& S){
    out << "{ ";
    for(const auto& s:S) out << s << " ";
    return (out << "}");
}
template<class L, class R, class chash = std::hash<L> > ostream& operator << (ostream &out, gp_hash_table<L, R, chash> const& M) {
    out << "{ ";
    for(const auto& m: M) out << "(" << m.first << ":" << m.second << ") ";
    return (out << "}");
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.front() << " ", U.pop();
    return (out << "}");
}
#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...) 1
#endif

/*/---------------------------RNG----------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN,long long r = LLONG_MAX){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};

/*/---------------------------Defines----------------------/*/
#define ll long long
#define endl "\n"
#define all(v) (v).begin(),(v).end()



/*/-----------------------------Code begins----------------------------------/*/

template<typename T, const bool implicit>
struct TreapNode{
	static uniform_int_distribution<uint64_t> __generator;
	static mt19937_64 __rng;
	const uint64_t priority = __generator(rng);
	array<TreapNode*, 2> children{nullptr, nullptr};
	T value;
	bool __reverse = false;
	int subtree_size = 1;

	void apply(const T& parent_val){
		value.apply(parent_val);
	}
	void propagate(){
		for(int z = 0; z < 2; ++z){
			if (!children[z])
				continue;
			children[z] -> apply(value);
			children[z] -> __reverse ^= __reverse;
		}
		if (__reverse){
			swap(children[0], children[1]);
			__reverse = false;
		}
		value.clear();
	}

	void pull(){
		subtree_size = 1;
		array<T*, 2> args; 
		for(int z = 0; z < 2; ++z){
			if (!children[z]){
				args[z] = nullptr;
			}
			else{
				args[z] = &(children[z] -> value);
				subtree_size += children[z] -> subtree_size;
			}
		}
	}

	static inline int sub_size(const TreapNode<T, implicit>* a) {
		if (!a)
			return 0;
		return a -> subtree_size;
	}

	static TreapNode<T, implicit>* merge(TreapNode<T, implicit>* a, TreapNode<T, implicit>* b){
		if (!a && !b)
			return nullptr;
		if (!a) {
			b -> propagate(); b -> pull(); 
			return b;
		}
		if (!b) {
			a -> propagate(); a -> pull(); 
			return a;
		}

		if (a -> priority < b -> priority){
			a -> propagate();
			a -> children[1] = merge(a -> children[1], b);
			a -> pull();
			return a;
		}
		else{
			b -> propagate();
			b -> children[0] = merge(a, b -> children[0]);
			b -> pull();
			return b;
		}
	}

	template<typename Q>
	static TreapNode<T, implicit>* erase(TreapNode<T, implicit>* root, Q key){
		if (!root)
			return root;
		root -> propagate();

		int own_value = (implicit ? sub_size(root -> children[0]) + 1 : 0);
		bool go_right = ((implicit && own_value <= key) || (!implicit && root -> value < key));

		if ((implicit && own_value == key + 1) || (!implicit && root -> value == key)){
			return merge(root -> children[0], root -> children[1]);
		}
		else if (go_right){
			root -> children[1] = erase(root -> children[1], key - own_value);
		}
		else{
			root -> children[0] = erase(root -> children[0], key);
		}
		root -> pull();
		return root;
	}



	template<typename Q>
	static pair<TreapNode<T, implicit>*, TreapNode<T, implicit>*> split(TreapNode<T, implicit>* x, Q y){
		if (!x) return {nullptr, nullptr};
		x -> propagate();
		TreapNode<T, implicit> *l, *r;
		int own_value = (implicit ? sub_size(x -> children[0]) + 1 : 0);
		if ((implicit && own_value <= y) || (!implicit && x -> value < y)){
			l = x;
			tie(l -> children[1], r) = split(x -> children[1], y - own_value);
		}
		else{
			r = x;
			tie(l, r -> children[0]) = split(x -> children[0], y);
		}
		x -> pull();
		return {l, r};
	}

	static TreapNode<T, implicit>* insert(TreapNode<T, implicit>* root, TreapNode<T, implicit>* node, int idx = -1){
		if (!root)
			return node;
		assert (node);
		root -> propagate();
		int own_value = (implicit ? sub_size(root -> children[0]) + 1 : 0);
		bool go_right = ((implicit && own_value <= idx) || (!implicit && root -> value < node -> value));

		if (!implicit && root -> value == node -> value){
			root -> pull();
			return root;
		}
		if (root -> priority < node -> priority){
			if (go_right){
				root -> children[1] = insert(root -> children[1], node, idx - own_value);
			}
			else{
				root -> children[0] = insert(root -> children[0], node, idx);
			}
			root -> pull();
			return root;
		}
		else{
			tie(node -> children[0], node -> children[1]) = (implicit ? split(root, idx) : split(root, node -> value));
			node -> pull();
			return node;
		}
	}



	template<typename Q>
	static int order_of_key(TreapNode<T, false>* root, Q key){ // faster than split + merge
		if (!root)
			return 0;
		root -> propagate();
		if (root -> value == key){
			return sub_size(root -> children[0]) + 1;
		}
		else if (root -> value < key){
			return sub_size(root -> children[0]) + 1 + order_of_key(root -> children[1], key);
		}
		else{
			return order_of_key(root -> children[0], key);
		}
	}

	static TreapNode<T, implicit>* find_by_order(TreapNode<T, false>* root, int k){
		if (!root)
			return nullptr;
		root -> propagate();
		if (sub_size(root -> children[0]) == k){
			return root;
		}
		else if (sub_size(root -> children[0]) < k){
			return find_by_order(root -> children[1], k - sub_size(root -> children[0]) + 1);
		}
		else{
			return find_by_order(root -> children[0], k);
		}
	}


	TreapNode<T, true>* reverse(TreapNode<T, true>* root, int l, int r){
		if (l > r)
			return root;
		TreapNode<T, true>* a, b, c;
		tie(b, c) = split(root, r + 1);
		tie(a, b) = split(b, l);
		assert (b);

		b -> __reverse ^= 1;
		b -> propagate();

		return merge(a, merge(b, c));
	}

};


template<typename T, const bool implicit>
ostream& operator << (ostream& os, const TreapNode<T, implicit>* p) {
	if (!p)
		return os;
	if (p -> children[0])
		os << p -> children[0] << " ";
	return os << p -> value << " " << p -> children[1];
}



template<typename T, const bool implicit>
uniform_int_distribution<uint64_t> TreapNode<T, implicit>::__generator(0, numeric_limits<uint64_t>::max());

template<typename T, const bool implicit>
mt19937_64 TreapNode<T, implicit>::__rng(chrono::steady_clock::now().time_since_epoch().count());






struct item{
	int x;
	operator int() const {
		return x;
	}
	void apply(const item& y){

	}
	void clear(){

	}
	bool operator < (int z) const {
		return x < z;
	}

	bool operator < (const item& z) const {
		return x < z.x;
	}

	friend ostream& operator << (ostream& os, const item& p) {
		return os << p.x;
	}
};


void solve(){
    

    int n, k;
    cin >> n >> k;

    long long mx = 10000;
    vector<TreapNode<item, false>*> T(mx + 1, nullptr);


    vector<array<long long, 3>> a(n);
    cin >> a;
    sort(all(a));
    vector<array<long long, 3>> b = a;
    sort(all(b), [&] (const array<long long, 3>& X, const array<long long, 3>& Y){
    	return X[0] + X[1] < Y[0] + Y[1];
    });
    int ctr = 0;
    vector<TreapNode<item, false>> nodes(n + 1);

    long long ans = 0;
    int j = 0;
    for(auto [x, R, f]: a){

    	while (j < n && b[j][0] + b[j][1] < x){
    		TreapNode<item, false>* root = T[b[j][2]];
    		T[b[j][2]] = TreapNode<item, false>::erase(T[b[j][2]], b[j][0]);
    		++j;
    	}
    	for(int z = max(f - k, 1LL); z <= min(f + k, mx); ++z){
	    	ans += (T[z] ? T[z] -> subtree_size: 0) - TreapNode<item, false>::order_of_key(T[z], x - R - 1);
	    }
		
    	TreapNode<item, false> *curr = &nodes[ctr++];
    	curr -> value.x = x;
    	T[f] = TreapNode<item, false>::insert(T[f], curr);
    	

    }
    cout << ans << endl;

}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}