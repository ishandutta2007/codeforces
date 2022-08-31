#include <bits/stdc++.h>
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

#define cerr cout

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
#define trace(...) 1
#endif

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase,insert same as normal set

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define I insert 
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define all(v) (v).begin(),(v).end()
#define For(i,n) for(int i=0;i<(int)n;++i)
#define Rev(i,n) for(int i=(int)n-1;i>=0;--i)
#define Rep(i,n) for(int i=1;i<=(int)n;++i)
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MP make_pair

// #define d0(x) cout<<(x)<<" "
// #define d1(x) cout<<(x)<<endl
// #define d2(x,y) cout<<(x)<<" "<<(y)<<endl
// #define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl


// // const int mod=1e9+7;
// inline int mul(int a,int b){return (a*1ll*b)%mod;}
// inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
// inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
// inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
// inline int inv(int a){return power(a,mod-2);}
// inline void modadd(int &a,int &b){a+=b;if(a>=mod)a-=mod;} 
const int N = 105;

int A[N][N];


int main(){
	fio; cout<<fixed<<setprecision(25);
	int n ,m;
	cin >> n >> m;
	for(int i = 1;i <= m ; i++){
		for(int j = 1; j <= n ; j++){
			cin >> A[i][j];
		}
	}
	vi Ans;
	for(int i = 1;i <= m; i++)
		Ans.pb(i);
	for(int i = 1;i <= n-1 ; i++){
		pll arr[m];
		for(int j = 0;j < m ; j++){
			arr[j] = {A[j+1][n] - A[j+1][i] , j+1}; 
		}
		sort(arr , arr+ m);
		
		ll sum = 0;
		if(arr[0].F > 0)
			continue;
		int j;
		for( j = 0;j < m; j++){
			sum += arr[j].F;
			if(sum > 0)
				break;
		}
		if(m-j < Ans.size()){
			Ans.clear();
			for( ;j < m ; j++)
				Ans.pb(arr[j].S);
		}
	}
	cout << Ans.size() << endl;
	for(auto it : Ans)
		cout << it << ' ';
	cout << endl;
}