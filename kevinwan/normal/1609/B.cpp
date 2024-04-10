#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);
const int mn = 4e5+10;
const ll mod = 998244353;

bool av[mn];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int num=0;
	for(int i=0;i<n-2;i++){
		if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')av[i]=1,++num;
	}
	while(m--){
		int ind;
		char c;
		cin>>ind>>c;
		--ind;
		s[ind]=c;
		for(int i=0;i<3&&ind-i>=0;i++)if(ind-i+2<n){
			num-=av[ind-i];
			av[ind-i]=0;
			if(s[ind-i]=='a'&&s[ind-i+1]=='b'&&s[ind-i+2]=='c'){
				av[ind-i]=1;
				++num;
			}
		}
		printf("%d\n",num);
	}
}