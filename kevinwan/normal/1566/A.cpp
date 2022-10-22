#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef array<ll,21> farray;

const int mn = 8e5+10;
const ll mod = 1e9+7;

int solve(){
	ll n,s;
	cin>>n>>s;
	ll num=n/2+1;
	printf("%lld\n",s/num);
	return 0;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	for(int tcc=1;tcc<=tc;++tcc){
		int temp;
		if(temp = solve()) {
			cerr << "Case #"<<tcc << ": Invalid Return" << temp << endl;
		}
	}
}