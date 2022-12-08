#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 5123
#define INF INT_MAX
#define MOD (1ll<<(32)) 
#define pii pair<int,int>
#define double long double 



map<int,double> m;
map<int,double> m2;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<setprecision(11)<<fixed;

	string s;
	cin>>s;
	int pos=0;
	for(char c:s){
		if(c=='+')pos++;
		else pos--;
	}
	cin>>s;
	m[0]=1;
	for(char c:s){
		m2.clear();
		for(auto x:m){
			if(c=='+')m2[x.f+1]+=x.s;
			if(c=='-')m2[x.f-1]+=x.s;
			if(c=='?'){
				m2[x.f+1]+=x.s/2;
				m2[x.f-1]+=x.s/2;
			}
		}
		m=m2;
	}
	cout<<m2[pos]<<endl;


	return 0;
}