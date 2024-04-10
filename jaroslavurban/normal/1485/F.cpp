#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;

const int N=200100,mod=1e9+7;
int b[N];
int n;

template<typename K,typename V>
struct HashMap{
	map<K,V>mp;
	K delta=0; // insertedkey + delta = newkey
	int count(K key){return mp.count(key-delta);}
	V &operator[](K key){return mp[key-delta];}
	void erase(K key){mp.erase(key-delta);}
	void insert(pair<K,V>item){mp.insert(item);}
	void shift(K d){delta+=d;} // adds d to all keys
};

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>b[i];
		int sum=1;
		HashMap<ll,ll>hm;
		hm[0]=1;
		for(int i=0;i<n;++i){
			hm.shift(b[i]);
			ll add=(sum-hm[b[i]])%mod;
			hm[b[i]]=(hm[b[i]]+add)%mod;
			sum=(sum+add)%mod;
		}
		cout<<(sum+mod)%mod<<endl;
	}
}