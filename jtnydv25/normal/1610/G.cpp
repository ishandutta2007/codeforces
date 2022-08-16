#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef unsigned uint;
typedef unsigned char uint8;

struct MOD{
    ull mod;
    ld invMOD;
    MOD(ull mod) : mod(mod), invMOD(1. / mod){}
    inline ull add(ull x, ull y){ x += y; if(x >= mod) x -= mod; return x;}
    inline ull sub(ull x, ull y){ x -= y; if(ll(x) < 0) x += mod; return x;}
    inline ll mul(ull a, ull b) {
        ull y = ull(ld(a) * ld(b) * invMOD + ld(1) / 2);
        ull r = a * b - y * mod;
        if(ll(r) < 0)
            r += mod;
        return r;
    }
    inline ull powr(ull a, ull b){
        ull x = 1 % mod;
        while(b){
            if(b & 1) x = mul(x, a);
            a = mul(a, a);
            b >>= 1;
        }
        return x;
    }
    inline ull inv(ull a){ return powr(a, mod - 2);}
};

const ull mod = 10000000000000061LL;
MOD operations_mod(mod);

struct int_mod{
    ull val;
    int_mod(){}
    int_mod(ull val) : val(val){}
    int_mod operator + (const int_mod & other) const{
        return int_mod(operations_mod.add(val, other.val));
    }
    int_mod operator - (const int_mod & other) const{
        return int_mod(operations_mod.sub(val, other.val));
    }
    int_mod operator * (const int_mod & other) const{
        return int_mod(operations_mod.mul(val, other.val));
    }
    int_mod operator / (const int_mod & other) const{
        return int_mod(operations_mod.mul(val, operations_mod.inv(other.val)));
    }
    int_mod inverse(){
        return int_mod(operations_mod.inv(val));
    }
    bool operator == (const int_mod & other) const{
        return val == other.val;
    }
    void print(){
        printf("%lld ", val);
    }
    void println(){
        printf("%lld\n", val);
    }
};

const int N = 300005;
const int base = 541;
int_mod powers[N];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	powers[0] = 1;
	for(int i = 1; i < N; i++) powers[i] = powers[i - 1] * base;
	string s; cin >> s;
	int n = s.length();
	vector<int> pref(n + 1);
	for(int i = 1; i <= n; i++){
		pref[i] = 2 * (s[i - 1] == '(') - 1 + pref[i - 1];
	}
	vector<int> nxt(n  + 1);
	stack<int> stk;
	for(int i = n; i >= 0; i--){
		while(!stk.empty() && pref[stk.top()] > pref[i]) stk.pop();
		nxt[i] = n + 1;
		if(!stk.empty()) nxt[i] = stk.top();
		stk.push(i);
	}
	vector<int> ptr(n + 2);
	const int L = __lg(n) + 1;
	vector<vector<int_mod>> Hash(L + 1, vector<int_mod>(n + 2));
	vector<vector<int>> par(L + 1, vector<int>(n + 2));
	int z = 0;
	function<void(int, int, char)> make = [&](int x, int p,  char c){
		Hash[0][x] = c;
		par[0][x] = p;
		for(int i = 1; i <= L; i++){
			par[i][x] = par[i - 1][par[i - 1][x]];
			Hash[i][x] = Hash[i - 1][x] * powers[1 << (i - 1)] + Hash[i - 1][par[i - 1][x]];
		}
	};
	make(0, 0, 1);
	for(int i = n; i >= 1; i--){
		make(++z, ptr[i + 1], s[i - 1]);
		if(s[i - 1] == ')' || nxt[i - 1] > n){
			ptr[i] = z;
		} else{
			int u = ptr[nxt[i - 1] + 1];
			int U = u, Z = z;
			for(int j = L; j >= 0; j--){
				if(Hash[j][U] == Hash[j][Z]){
					U = par[j][U];
					Z = par[j][Z];
				}
			}
			ptr[i] = Hash[0][Z].val < Hash[0][U].val ? z : u;
		}
	}
	int h = ptr[1];
	while(h != 0){
		cout << (char)(Hash[0][h].val);
		h = par[0][h];
	}
	cout << endl;
	
}