#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
const int LN = 30;
struct trie{
	struct node{
		node * ch[2];
		int size;
		node(){ch[0] = ch[1] = NULL; size = 0;}

		int eval(){
			if(size == 1){
				return 0;
			}
			int L = ch[0] ? ch[0]->size : 0;
			int R = ch[1] ? ch[1]->size : 0;
			int A = ch[0] ? ch[0]->eval() : 0;
			int B = ch[1] ? ch[1]->eval() : 0;
			if(L <= 1 || R <= 1){
				return A + B;
			}
			return min(L - 1 + B, R - 1 + A);
		}
	};
	node * root;
	trie(){root = new node();}
	void insert(int v){
		node * x = root; 
		for(int i = LN - 1; i >= 0; i--){
			x->size++;
			int d =  v >> i & 1;
			if(!x->ch[d]) x->ch[d] = new node();
			x = x->ch[d];
		}
		x->size++;
	}
	int get(){
		return root->eval();
	}
};
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	trie T;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		T.insert(x);
	}
	cout << T.get() << endl;
}