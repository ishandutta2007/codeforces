#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif
#define mp 			make_pair
#define int 		long long
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define hell2 		1000000009
#define F 			first
#define S 			second
#define pow10 powkjadben
using namespace std;
vector<pii>x;
vector<pii>pow10;
pii hashing(int l,int r){
	int hash1=((x[r].F-1LL*x[l-1].F*pow10[r-l+1].F)%hell+hell)%hell;
	int hash2=((x[r].S-1LL*x[l-1].S*pow10[r-l+1].S)%hell2+hell2)%hell2;
	return mp(hash1,hash2);
}
bool check(pii a,pii b,pii c){
	return (a.F+b.F)%hell==c.F and (a.S+b.S)%hell2==c.S;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int n=s.length();
	x.resize(n+1);
	pow10.resize(n+1);
	pow10[0]=mp(1,1);
	for(int i=1;i<=n;i++){
		pow10[i]=mp(pow10[i-1].F*10LL%hell,pow10[i-1].S*10LL%hell2);
	}
	for(int i=1;i<=n;i++){
		x[i].F=(x[i-1].F*10LL+s[i-1]-'0')%hell;
		x[i].S=(x[i-1].S*10LL+s[i-1]-'0')%hell2;
	}
	for(int i=n/2;i<=n;i++){
		int l=n-i+1;
		if(s[i-1]=='0' && i!=n) continue;
		if(i-l-1>0 && i-1>0 && check(hashing(1,l),hashing(l+1,i-1),hashing(i,n)) && (i-1-l==1 || s[l]!='0') && (s[0]!='0' || l==1))
		{
			cout<<s.substr(0,l)<<"+"<<s.substr(l,i-l-1)<<"="<<s.substr(i-1);
			return 0;
		}
		if(l-1>0 && i-l>0 && check(hashing(1,l-1),hashing(l,i-1),hashing(i,n)) && (i-l==1 || s[l-1]!='0') && (s[0]!='0' || l==2)) 
		{
			cout<<s.substr(0,l-1)<<"+"<<s.substr(l-1,i-l)<<"="<<s.substr(i-1);
			return 0;
		}
		if(i-l-1>0 && l>0 && check(hashing(1,i-l-1),hashing(i-l,i-1),hashing(i,n)) && (l==1 || s[i-l-1]!='0') && (s[0]!='0' || i-l-1==1))
		{
			cout<<s.substr(0,i-l-1)<<"+"<<s.substr(i-l-1,l)<<"="<<s.substr(i-1);
			return 0;
		}
		if(i-l>0 && l-1>0 && check(hashing(1,i-l),hashing(i-l+1,i-1),hashing(i,n)) && (l-1==1 || s[i-l]!='0') && (s[0]!='0' || i-l==1))
		{
			cout<<s.substr(0,i-l)<<"+"<<s.substr(i-l,l-1)<<"="<<s.substr(i-1);
			return 0;
		}
	}
	return 0;
}