    #include<iostream>
    #include<vector>
    #include<map>
    #include<set>
    #include<cassert>
    #include<cassert>
    #include<unordered_map>
    #include<unordered_set>
    #include<functional>
    #include<queue>
    #include<stack>
    #include<cstring>
    #include<algorithm>
    #include<cmath>
    #include<sstream>
    #include<iomanip>
    #include<cstdio>
    #include<cstdlib>
    #include<numeric>
    #include<random>
    #include<chrono>
    #include<bitset>
    using namespace std;
     
    #define all(x) (x).begin(), (x).end()
    #define pb push_back
    #define xx first
    #define yy second
    #define sz(x) (int)(x).size()
    #define gc getchar
    #define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
    #define mp make_pair
     
    #ifndef ONLINE_JUDGE
    #  define LOG(x) (cerr << #x << " = " << (x) << endl)
    #else
    #  define LOG(x) ((void)0)
    #endif
     
    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double ld;
     
    const double PI=acos(-1);
    const ll INF = 1LL<<62;
    const ll MINF = -(1LL<<62);
     
    template<typename T> T getint() {
    	T val=0;
    	char c;
    	
    	bool neg=false;
    	while((c=gc()) && !(c>='0' && c<='9')) {
    		neg|=c=='-';
    	}
     
    	do {
    		val=(val*10)+c-'0';
    	} while((c=gc()) && (c>='0' && c<='9'));
     
    	return val*(neg?-1:1);
    }
     
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); uniform_int_distribution<int>(0, n-1)(rng)
     
     
    int main() {
    	IO;
    	int n;
    	cin>>n;
    	set<ll> fire, light, osz;
    	ll sum_fire=0, sum_light=0;
    	set<ll> kicsi, nagy;
    	ll ksum=0,nsum=0;
    	auto del=[&](ll x) {
    		if(kicsi.find(x)!=kicsi.end()) {
    			kicsi.erase(x);
    			ksum-=x;
    		}else {
    			nagy.erase(x);
    			nsum-=x;
    		}
    	};
    	auto fix=[&]() {
    		while(!kicsi.empty() && !nagy.empty() && *prev(kicsi.end())>*nagy.begin()) {
    			ll val=*prev(kicsi.end());
    			nagy.insert(val);nsum+=val;
    			kicsi.erase(val);ksum-=val;
    		}
    		while(sz(nagy)>sz(light)) {
    			ll val=*nagy.begin();
    			nagy.erase(val);
    			nsum-=val;
    			ksum+=val;
    			kicsi.insert(val);
    		}
    		
    		while(sz(nagy)<sz(light) && sz(kicsi)>0) {
    			ll val=*prev(kicsi.end());
    			kicsi.erase(val);
    			ksum-=val;
    			nsum+=val;
    			nagy.insert(val);
    		}
    		
    		if(sz(nagy)==sz(light) && sz(light)>0 && nagy.find(*light.begin())!=nagy.end()) {
    			if(sz(kicsi)==0) {
    				kicsi.insert(*light.begin());ksum+=*light.begin();
    				nagy.erase(*light.begin());nsum-=*light.begin();
    			}else {
    				ll biggest=*prev(kicsi.end());
    				
    				kicsi.insert(*light.begin());ksum+=*light.begin();
    				nagy.erase(*light.begin());nsum-=*light.begin();
    				
    				kicsi.erase(biggest);ksum-=biggest;
    				nagy.insert(biggest);nsum+=biggest;
    			}
    		} 
    		
    		/*ll kksum=0, nnsum=0;
    		for(auto i:kicsi) kksum+=i;
    		for(auto i:nagy) nnsum+=i;
    		assert(kksum==ksum);
    		assert(nnsum==nsum);*/
    	};
    	for(int i=0;i<n;++i) {
    		ll a,b;
    		cin>>a>>b;
    		if(b<0) {
    			if(a==0) {
    				fire.erase(-b);
    				sum_fire-=-b;
    				del(-b);
    				fix();
    			}else {
    				light.erase(-b);
    				sum_light-=-b;
    				del(-b);
    				fix();
    			}
    			osz.erase(-b);
    		}else {
    			if(a==0) {
    				fire.insert(b);
    				sum_fire+=b;
    				nagy.insert(b);nsum+=b;
    				fix();
    			}else {
    				light.insert(b);
    				sum_light+=b;
    				nagy.insert(b);nsum+=b;
    				fix();
    			}
    			osz.insert(b);
    		}
    		
    		//~ vector<ll> lst;
    		//~ for(auto i:osz) lst.pb(i);
    		
    		//~ ll nsum2=0;
    		//~ ll ssz=0;
    		//~ for(int i=sz(lst)-1;i>=sz(lst)-sz(light);i--) {
    			//~ ssz++;
    			//~ nsum2+=lst[i];
    		//~ }
    		//~ if(sz(light)>0 && *light.begin()>=lst[sz(lst)-sz(light)]) {
    			//~ ssz--;
    			//~ nsum2-=*light.begin();
    			//~ if(sz(lst)-sz(light)>0) {
    				//~ nsum2+=lst[sz(lst)-sz(light)-1];
    				//~ ssz++;
    			//~ }
    		//~ }
    		
    		//~ LOG(nsum);
    		//~ LOG(nsum2);
    		//~ LOG(ssz);
    		//~ LOG(sz(light));
    		//~ for(auto j:kicsi) LOG(j);
    		//~ for(auto i:nagy) LOG(i);
    		//~ assert(nsum==nsum2);
    		
    		cout<<sum_fire+sum_light+nsum<<"\n";
    	}
    	return 0;
    }