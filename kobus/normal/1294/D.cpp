#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 312345;
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define MOD 1000000007


int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	int q,x;
	cin>>q>>x;

	int at=0;
	vector<int> v(x);

	for(int i=0;i<q;i++){
		int y;
		cin>>y;
		v[y%x]++;
		while(v[at%x]>at/x)at++;
		cout<<at<<endl;
	}

}