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
#define For(i,n) for(int i=0;i<n;i++)
pair<int,int> arr[100500];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	int n,m,h=0;
	bool f=true;
	cin>>n>>m;
	For(i,m){
		cin>>arr[i].S>>arr[i].F;

	}

	For(i,m-1){
		int diff=arr[i+1].S-arr[i].S;
		int h1=min(arr[i].F,arr[i+1].F);
		int h2=max(arr[i].F,arr[i+1].F);
		if (h2-h1>diff){
			f=false;
			break;
		}
		diff-=h2-h1;
		h=max(h,h2+(diff/2));
	}
	h=max(arr[0].F+arr[0].S-1,h);
	h=max(arr[m-1].F+(n-arr[m-1].S),h);
	if (f){
		cout<<h;
	}
	else{
		cout<<"IMPOSSIBLE";
	}


}