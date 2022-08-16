#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> ostream& operator<<(ostream& os, vector<T> V){
	os<<"[ "; for(auto v : V) os << v << " "; return os<<"]";
}
template<class L, class R> ostream& operator<<(ostream& os, pair<L, R> P){
	return os<< "(" << P.first << " , " << P.second << ")";
}
#define TRACE
#ifdef TRACE
template< typename Arg1>
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
void __f(const char* name, Arg1&& arg1){
	cout << name << ": "<< arg1 << endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma=strchr(names+1 , ','); cout.write(names, comma-names) << " : " << arg1 << " | ";
	__f(comma+1 , args...);
}
#else 
#define trace(...) 1
#endif
#define ll unsigned long long
#define ld long double
#define pll pair<ll, ll> 
#define pii pari<int, int>
#define F first
#define S second
#define I insert
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vll vector<ll>

const int N=30;
ll ncr[N][N];


void pre(){
	ncr[0][0]=1;


	for(ll i=1;i<N;++i){
		ncr[i][0]=ncr[i][i]=1;
		for(ll j=1;j<i;++j){

			ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
			// trace(i,j,ncr[i][j]);
		}

	}

}

void solve(){
	ll n;
	cin>>n;
	vector<ll> res;
	int k=2;
	// trace(n);
	while(n){
		res.pb(n%k);
		n/=k;
		++k;
	}

	--k;
	ll ex=k;
	sort(all(res));
	// trace(res);
	map<ll,ll> vals;
	map<ll,ll> cnt;
	 // res.sort()
    // ex=k
    ll tot=1;
    ll tt=1;
    ll cn=0;
    for(long long i=res.size()-1;i>=0;--i){
    	if (res[i]==0) break;
    	cnt[res[i]]++;
    	while(res[i]<ex-1) --ex;
    	if (vals.find(res[i])==vals.end()){
    		vals[res[i]]=k-ex+1-cn;
    		// trace(res[i],k,ex,cn);
    	}
    	++cn;

    }

    for(auto z:vals){
    	ll X=z.F,Y=z.S;
    	ll t=Y,r=cnt[X];
    	// trace(t,r);
    	tot*=ncr[t][r];
    	tt*=ncr[t-1][r];
    }
    // trace(tot,tt);
    cout<<tot-tt-1<<endl;


    // for i in xrange(len(res)-1,-1,-1):
    //     if (res[i]==0):
    //         break
    //     while(res[i]<ex-1):
    //         ex-=1
    //     tot*=(k-ex+1-cn)
    //     tt*=(k-ex-cn)
    //     cn+=1
    // tot-=tt;
    // d={}
    // for i in res:
    //     if (i==0):
    //         continue
    //     try:
    //         d[i]+=1
    //     except:
    //         d[i]=1
            
    // for i in d:
    //     tot/=fact[d[i]]
    // print (tot-1)
    

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(25);
	int t;
	cin>>t;
	pre();
	while(t--){
		solve();		
	}
	return 0;
}