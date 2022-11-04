    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef long double ld;
    #define ff first
    #define ss second
    #define all(x) (x).begin(), (x).end()
    #define sz(w) (ll) w.size()
    #define frx(x,z,y) for(ll x=z;x<y;++x)
    #define fr(x,y) frx(x,0,y)
    #define inf 9e18+1
    // use unique(x) - removec consecutive items, returns vec.begin() + number of items
    // for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
    // use iota(all(vec), 0) for filling a vector with 0,1,2...
    // use fill(all(vec), 1) for filling a vector with 1,1,1...
    // use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
    // use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
    // ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
    // print number in binary -> cout << bitset<20>(n);
     
    ll cnts[200010][20];
    vector<ll> a; // a[i]=highest prime factor of i
    vector<ll> erat (ll n){
        a = vector<ll>(n,0);
        vector<ll> primes;
        a[0] = a[1] = 1;
        for (ll i = 2; i < n; ++i){
            if (!a[i]){
                primes.push_back(i);
                for (ll j = i; j < n; j += i) a[j] = i;
            }
        }
        return primes;
    }
    void getprimes(ll num){
    	ll idx=0;
    	while (num!=1){
    		cnts[a[num]][idx]++;
    		if(a[num/a[num]]==a[num]){
    			++idx;
    		} else idx=0;
    		num/=a[num];
    	}
    }
     
    int main(){
    	erat(200001);
    	ll n;cin>>n;
    	fr(i,n){
    		ll num;cin>>num;getprimes(num);
    	}
    	ll res=1;
    	fr(i,200000)
    		fr(j,20)
    			if(cnts[i][j]>=n-1)
    				res*=i;
    	cout<<res<<endl;
    }