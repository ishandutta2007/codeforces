#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

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

map<int, vector<int> > indices;
const int N = 1000005;
string s[N], t[N];

#define ld long double
const ll mod = 1e16 + 61;
const int base = 31;
ld inv = 1. / (ld)mod;

ll mul(ll a, ll b){
    ll x = (ll)((ld)a*(ld)b*inv +(ld)(1)/2.);
    ll ret = a*b-mod*x;
    if((ll)(ret) < 0)
        ret+=mod;
    return ret;
}

ll add(ll a, ll b){
	 a += b;
	 if(a >= mod) a -= mod;
	 return a;
}

ll sub(ll a, ll b){
	a -= b;
	if(a < 0) a += mod;
	return a;
}

char c[N];

vector<vector<int> > groups;

map<ll, vector<int> > grouping;

int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		scanf("%s", c);
		s[i] = (string)c;
		scanf("%s", c);
		t[i] = (string) c;

		int msk = 0;
		for(int j = 0; j < t[i].length(); j++) msk |= (1 << (t[i][j] - 'a'));
		indices[msk].push_back(i);
	}

	for(auto it : indices){	
		vector<int> V = it.S;
		int msk = it.F;

		for(int i : V){
			int j = s[i].length() - 1;
			for(j = s[i].length() - 1; j >= 0; j--){
				if(!(msk & (1 << (s[i][j] - 'a')))){
					break;
				}
			}
			ll H = 0;
			for(int k = 0; k <= j; k++) H = (H * base + (s[i][k] - 'a') + 1) % mod;
			grouping[H].push_back(i);
		}
		for(auto it2 : grouping) groups.push_back(it2.S);
		grouping.clear();
	}
	printf("%d\n", (int)groups.size());
	for(auto it : groups){
		printf("%d ", (int)it.size());
		for(auto i : it) printf("%d ", i);
		printf("\n");
	}
}