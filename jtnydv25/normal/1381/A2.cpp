#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

// mt19937_64 for 64 bit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int getRand(int x, int y){
	return uniform_int_distribution<int>(x, y)(rng);
}

template<class T>
struct implicit_treap{
	struct node{
		int lazy, key, size;
		T value;
		node* ch[2];
		node(){ch[0] = ch[1] = NULL; lazy = value = 0; key = getRand(0, 1 << 30); size = 1;}
		node(T v){
			ch[0] = ch[1] = NULL; lazy = 0; key = getRand(0, 1 << 30); size = 1; value = v;
		}
		void push(){
			if(lazy){
				value ^= 1;
				swap(ch[0], ch[1]);
				if(ch[0]) ch[0]->lazy ^= 1;
				if(ch[1]) ch[1]->lazy ^= 1;
			}
			lazy = 0;
			size = 1 + (ch[0] ? ch[0]->size : 0) + (ch[1] ? ch[1]->size : 0);
		}
	};

	node * root;

	implicit_treap(){root = NULL;}

	node* merge(node * A, node * B){
		if(A) A->push();
		if(B) B->push();
		if(!A) return B;
		if(!B) return A;
		if(A->key > B->key){
			A->ch[1] = merge(A->ch[1], B);
			A->push();
			return A;
		} else{
			B->ch[0] = merge(A, B->ch[0]);
			B->push();
			return B;
		}
	}

	void insert(int v){
		node * nw = new node(v);
		root = merge(root, nw);
	}

	// smallest n
	pair<node*, node*> split(node * X, int n){
		if(n == 0){
			return {NULL, X};
		}
		X->push();
		int lft = X->ch[0] ? X->ch[0]->size : 0;
		if(lft >= n){
			pair<node*, node*> P = split(X->ch[0], n);
			X->ch[0] = P.second;
			X->push();
			return {P.first, X};
		}
		else{
			pair<node*, node*> P = split(X->ch[1], n - lft - 1);
			X->ch[1] = P.first;
			X->push();
			return {X, P.second};
		}
	}

	node* getKth(node * X, int k){
		X->push();
		int lft = X->ch[0] ? X->ch[0]->size : 0;
		if(lft >= k) return getKth(X->ch[0], k);
		else if(lft == k - 1) return X;
		else return getKth(X->ch[1], k - lft - 1);
	}

	int get(int k){
		return getKth(root, k)->value;
	}
	void printAll(node* nd){
		for(int i = 1; i <= nd->size; i++) cerr << getKth(nd, i)->value << " ";
		cerr << endl;
	}
	void reverse(int n){
		pair<node*, node*> P = split(root, n);
		P.first->push();
		P.first->lazy ^= 1;
		root = merge(P.first, P.second);
	}

};

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string a, b; cin >> a >> b;
		implicit_treap<int> A;
		for(int i = 0; i < n; i++) A.insert(a[i] == '1');
		vector<int> ans;
		for(int i = n - 1; i >= 0; i--){
			// cerr<<a << endl;
			if(A.get(i + 1) != (b[i] == '1')){
				if(i == 0){
					// a[0] = a[0] == '0' ? '1' : '0';
					A.reverse(1);
					ans.push_back(1);
					break;
				}
				if(A.get(1) == (b[i] == '1')){
					A.reverse(1);
					ans.push_back(1);
				}
				ans.push_back(i + 1);
				A.reverse(i + 1);
			}
		}
		cout << ans.size() << " ";
		for(int v : ans) cout << v << " ";
		cout << "\n";
		// for(int i  = 0; i <n; i++) cerr << A.get(i + 1); cerr << endl;
		// cerr << b << endl;
	}
}