#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define izq nod * 2
#define der nod * 2 + 1
#define mid (( a + b ) >> 1)
#define oo (1<<30)
#define oo64 (1LL<<62LL)
#define fr first
#define sc second
#define pb push_back
#define m_p make_pair
#define len(X) ((int)((X).size()))
#define all(X) (X).begin(), (X).end()
#define YES cout<<"YES"<<'\n'
#define NO cout<<"NO"<<'\n'
#define NO1 cout<<'-'<<'1'<<'\n'

using namespace std;

typedef long long int64;
typedef unsigned long long unt64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;


const int MX = 400005;
const int64 MOD = 1000000007; 

void solve(){
     int n,m;
     cin>>n>>m;
     int r,w;
     r = -oo;
     w = -oo;
     for ( int i = 1; i <= m; i++ ){
	      int ri,wi;
	      cin>>ri>>wi;
	      
	      r = max ( r, ri );	 
	      w = max ( w, wi );	 
	 }
	 
	 if ( r + w <= n ){
	     for ( int i = 1; i <= r; i++ ){
		      cout<<"R";
		 }
		 for ( int i = 1; i <= w; i++ ){
		      cout<<"W";
		 }
		 for ( int i = 1; i <= n - r - w; i++ )cout<<"W";
		 cout<< '\n';
	 } 
	 else cout<<"IMPOSSIBLE\n";
     
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int t; cin>>t;
    while( t-- ) 
          solve(); 	
	
return 0;	
}