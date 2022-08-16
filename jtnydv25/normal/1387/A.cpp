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

// assumption : denominator never 0

template<class T>
struct Rational{
	T gcd(T x, T y){
		if(x == 0) return y; if(y == 0) return x;
		return gcd(y, x % y);
	}
	T ABS(T x){return x >= 0 ? x : -x;}
    T num, den;
    Rational(T num, T den) : num(num), den(den){}
    Rational(T num) : num(num), den(1){}
    Rational() : num(0), den(1){}
    void reduce(){
		if(num == 0){
			den = 1;
			return; 
		}
        T g = gcd(ABS(num), ABS(den));
        num /= g; den /= g;
		if(den < 0) num *= -1, den *= -1;
    }
    void print(){
        cout << (ll)num << "/" << (ll)den << endl;
    }
    Rational operator - () const{
        return Rational(-num, den);
    }
    
    Rational operator + (const Rational & r) const{
        return Rational(num * r.den + den * r.num, den * r.den);
    }

    void operator += (const Rational & r){
        *this = (*this) + r;
    }

    Rational operator - (const Rational & r) const{
        return Rational(num * r.den - den * r.num, den * r.den);
    }

    void operator -= (const Rational & r){
        *this = (*this) - r;
    }

    Rational operator * (const Rational & r) const{
        return Rational(num * r.num, den * r.den);
    }

    void operator *= (const Rational & r){
        *this = (*this) * r;
    }

    Rational operator / (const Rational & r) const{
        return Rational(num * r.den, den * r.num);
    }

    void operator /= (const Rational & r){
        *this = (*this) / r;
    }

    bool operator < (const Rational & r) const{
        T up = num * r.den - den * r.num;
        if(up == 0) return 0;
        return (up < 0) ^ (den < 0) ^ (r.den < 0);
    }
	bool operator == (const Rational & r) const{
		return num == r.num && den == r.den;
	}
};

const ld EPS = 1e-10;

template<class T>
struct weighted_graph{
    vector<vector<pair<int, T>>> adj;
    int n;
    weighted_graph(){}
    weighted_graph(int n) : n(n), adj(n){}
    void add_edge(int a, int b, T w, bool directed = false){
        adj[a].push_back({b, w});
        if(!directed) adj[b].push_back({a, w});
    }

    void input(int m, int ind = 1, bool directed = false){
        for(int i = 0; i < m; i++){
            int u, v, w;
            // confirm weights fit into integers
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u - ind, v - ind, w, directed);
        }
    }
	void go(){
		vector<double> assignment(n);
		const Rational<ll> INF = Rational<ll>(1, 0);

		vector<int> vis(n);
		vector<pair<ll, ll>> dp(n);

		Rational<ll> curr;
		
		bool error = false;
		
		vector<int> nodes;
		function<void(int)> dfs = [&](int s){
			vis[s] = 1;
			// trace(s, dp[s]);
			nodes.push_back(s);
			for(auto it : adj[s]){
				int v = it.F;
				int w = it.S;
				pair<ll, ll> V = {-dp[s].F, w - dp[s].S};
				if(!vis[v]){
					dp[v] = V;
					dfs(v);
				} else{
					ll a = V.F - dp[v].F, b = dp[v].S - V.S;
					if(a == 0 && b == 0) continue;
					if(a == 0){
						error = true;
					} else{
						Rational<ll> possible = Rational<ll>(b, a); // x must be b / a
						possible.reduce();
						if(curr == INF){
							curr = possible;
						} else{
							if(!(curr == possible)){
								error = true;
							}
						}
					}
				}
			}
		};

		ll ans = 0;
		vector<double> X(n);
		for(int i = 0; i < n; i++) if(!vis[i]){
			// trace(i);
			dp[i] = {1, 0};
			curr = INF;
			nodes.clear();
			dfs(i);
			if(error){
				printf("NO\n");
				return;
			}
			ld lo = -10 * n, hi = 10 * n;
			if(!(curr == INF)){
				lo = curr.num / (double) curr.den;
				hi = lo;
			}
			else{
				for(int i = 0; i < 100; i++){
					ld m1 = (2 * lo + hi) / 3.;
					ld m2 = (2 * hi + lo) / 3.;
					ld X1 = 0, X2 = 0;
					for(int v : nodes){
						X1 += fabs(dp[v].F * m1 + dp[v].S);
						X2 += fabs(dp[v].F * m2 + dp[v].S);
					}

					if(X1 < X2){
						hi = m2;
					} else{
						lo = m1;
					}
				}
			}

			for(int v : nodes){
				ans += fabs(X[v] = dp[v].F * lo + dp[v].S);
			}
		}
		printf("YES\n");
		for(int i = 0; i < n; i++) printf("%.10lf ", X[i]);
		printf("\n");
	}
};

int main(){
	int n, m;
	sd(n); sd(m);
	weighted_graph<int> g(n);
	g.input(m);
	g.go();
}