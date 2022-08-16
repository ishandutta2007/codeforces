#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
 os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif


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
const int N=3e5;
int arr[N],pref[N],ans[N];


inline int cil(int n,int k){
	return (n+k-1)/k;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	int n,t,p,l,r;
	cin>>n;

	for(int i=0;i<n;i++) {cin>>arr[i+1];pref[i]=0;ans[i]=0;}
	pref[n]=0;
	for(int i=2;i<=n;i++){
		t=int(sqrt(i));
		// trace(i,t);
		for(int k=1;k<=t;k++){
			p=(i-2)/k;
			p++;
			// trace(p,k);
			if (arr[i]<arr[p]){
				// trace(i,p,k,arr[i],arr[p]);
				ans[k]++;
			}

		}
		p=(i-2)/t;
		p++;
		l=max(cil(i-1,p),t+1),r=n-1;
		if (p!=1){
			r=min(r,(i-2)/(p-1));
		}
		if(arr[i]<arr[p]){ pref[l]++;
			pref[r+1]--;
		}p--;

		// trace(p);
		while(p>=1){
			if (arr[i]>=arr[p]) {
				p--; continue;
			}

			l=cil(i-1,p),r=n-1;
			if (p!=1){
				r=min(r,(i-2)/(p-1));
			}
			// trace(l,r,p,i,arr[i]);
			pref[l]++;
			pref[r+1]--;
			p--;

		}
	}
	for(int i=1;i<n;i++){
		pref[i]+=pref[i-1];
		cout<<pref[i]+ans[i]<<" ";
	}
}