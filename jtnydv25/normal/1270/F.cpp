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
const int N = 200005;
char s[N];
int p[N];
ll V[N];
const int t = 2000;
vector<int> pos;
#define ull unsigned ll


 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<class T, class V, int MAX_FREE_FACTOR = (1<<20), int INIT_m = 3>
struct HashMap{
    int size, m, M;
    T * bucket;
    V * values;
    ull a;
    ull b;
    T MAX, MIN;
    int min_filled;
    void init(){
        a = uniform_int_distribution<ull>()(rng);
        if(a % 2 == 0) a++;
        b = uniform_int_distribution<ull>()(rng);
        m = INIT_m;
        M = 1 << m;
        bucket = new T[M];
        values = new V[M];
        size = 0;
        MAX = numeric_limits<T>::max();
        MIN = numeric_limits<T>::min();
        min_filled  = 0;
        fill(bucket, bucket + M, MIN);
        fill(values, values + M, numeric_limits<V>::min());
    }
 
    HashMap(){
        init();
    }
 
    //[0....M - 1]
    int h(T x){
        return (((ull) x) * a + b) >> (64 - m);
    }
    
    void reHash(int new_m){
        int oldM = M;
 
        T * bucket_copy = new T[M];
        V * values_copy = new V[M];
        copy(bucket, bucket + M, bucket_copy);
        copy(values, values + M, values_copy);
        delete [] bucket;
        delete [] values;
 
        M = (1 << new_m);
        m = new_m;
        min_filled = M / MAX_FREE_FACTOR;
        bucket = new T[M];
        values = new V[M];
        fill(bucket, bucket + M, MIN);
        fill(values, values + M, numeric_limits<V>::min());
 
        size = 0;
 
        for(int i = 0; i < oldM; i++){
            T v = bucket_copy[i];
            if(v != MIN && v != MAX) (*this)[v] = values_copy[i];
        }
 
        delete [] bucket_copy;
        delete [] values_copy;
    }
 
    V & operator [](T x){
        if(2 * size >= M){
            reHash(m + 1);
        }
        int pos = h(x);
        while(bucket[pos] != MIN){
            if(bucket[pos] == x){
                return values[pos];
            }
            pos = (pos + 1) & (M - 1);
        }
        bucket[pos] = x;
        values[pos] = 0;
        size++;
        return values[pos];
    }
    
    bool containsKey(T x){
        int pos = h(x);
        while(bucket[pos] != MIN){
            if(bucket[pos] == x){
                return true;
            }
            pos = (pos + 1) & (M - 1);
        }
        return false;
    }

    void put(T k, V v){
        (*this)[k] = v;
    }

    bool erase(T x){
        // no point in rehashing if m is already small and (1<<m) fits into cache
        if(size && size < min_filled && m > INIT_m + 5){
            reHash(m - 1);
        }
        int pos = h(x);
        while(bucket[pos] != MIN){
            if(bucket[pos] == x){
                bucket[pos] = MAX;
                values[pos] = numeric_limits<V>::min();
                size--;
                return true;
            }
            pos = (pos + 1) & (M - 1);
        }
        return false;
    }
 
    void clear(){
        delete [] bucket;
        delete [] values;
        init();
    }
 
    ~HashMap(){
        delete [] bucket;
        delete [] values;
    }
};


ll num(int a, int b, int c, int d, int r){
	ll t1 = (b - a + 1) / r;
	ll t2 = (d - c + 1) / r;
	int left1 = (b - a + 1) - t1 * r;
	int left2 = (d - c + 1) - t2 * r;
	ll ret = (b - a + 1) * t2 + (d - c + 1) * t1 - r * t1 * t2;
	int b2 = (c - a + r) % r;
	if(b2 < left1) ret += min(b2 + left2, left1) - b2;
	if(b2 + left2 - 1 >= r){
		ret += min(left1, left2 - (r - b2));
	}
	return ret;
}

int main(){
	scanf("%s", s);
	int n = strlen(s);
// 	int n = 200000;
	vector<int> positions;
	for(int i = 1; i <= n; i++){
// 		s[i-1] = (rand() % 2) + '0';
		p[i] = (p[i - 1] + (s[i - 1] == '1'));
		if(s[i - 1] == '1') positions.push_back(i);
	}

	ll ans = 0;
	int num1 = sz(positions);
	for(int i = 0; i < num1; i++){
		int max_pos = min(num1, i + t);
		int a = i == 0 ? 0 : positions[i - 1];
		int b = positions[i] - 1;
		for(int j = i; j < max_pos; j++){
			int c = positions[j];
			int d = (j == num1 - 1 ? n : positions[j + 1] - 1);
			ans += num(a, b, c, d, j - i + 1);
		}
	}
	for(int r = 1; r * (t + 1) <= n; r++){
		HashMap<int, int> all_freq;
		int L = r * t;
		for(int i = 1; i <= n; i++){
			int v = i - r * p[i];
			ans += all_freq[v];
			
			if(i - L >= 0) all_freq[i - L - r * p[i - L]]++;
		}
	}
	printf("%lld\n", ans);
}