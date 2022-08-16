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

char arr[55][55];
int ans[150][150];
bool vis[55][55];

vector<pair<int,int>> pieces;


inline bool check(int i,int j,int n){
	if (i<0 || j<0 || i>=n || j>=n) return true;
	if (arr[i][j]=='.') return false;
	return true;
}

inline void assign(int i,int j,int n){
	if (i<0 || j<0 || i>=n || j>=n) return;
	vis[i][j]=true;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	int n;
	cin>>n;
	For(i,n){
		For(j,n) {cin>>arr[i][j]; vis[i][j]=false;
			if (arr[i][j]=='o') pieces.pb(make_pair(i,j));
		}
	}

	For(i,2*n-1){
		For(j,2*n-1) ans[i][j]=-1;
	}
	ans[n-1][n-1]=0;
	For(i,2*n-1){
		For(j,2*n-1){
			if (ans[i][j]!=-1) continue;
			int dx=i-n+1;
			int dy=j-n+1;
			bool f=true;
			for (auto x:pieces){
				if (!(check(x.F+dx,x.S+dy,n))){
					f=false;
					break;
				}
			}
			if (f){
				ans[i][j]=1;
				for(auto x:pieces) assign(x.F+dx,x.S+dy,n);
			}
		}
	}
	bool tm=true;
	For(i,n){
		For(j,n){
			if (arr[i][j]=='x' && (!(vis[i][j]))){
				tm=false;
				break;
			}
			if (arr[i][j]=='.' && vis[i][j]){
				tm=false;
				break;
			}
		}
	}
	if (!(tm)){
		cout<<"NO";
	}
	else{
		cout<<"YES"<<"\n";

		For(i,2*n-1){
			For(j,2*n-1){
				if (ans[i][j]==-1) cout<<".";
				else if (ans[i][j]==0) cout<<"o";
				else cout<<"x";
			}
			cout<<"\n";
		}
	}



}