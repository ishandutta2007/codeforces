#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef array<ll,21> farray;

const int mn = 8e5+10;
const ll mod = 1e9+7;

int solve(){
	string s;
	cin>>s;
	int nc=0;
	char lc='1';
	for(char c:s){
		if(c!=lc)++nc;
		lc=c;
	}
	if(nc==0)printf("0\n");
	else if(nc<=2)printf("1\n");
	else printf("2\n");
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