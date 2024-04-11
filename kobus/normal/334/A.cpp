#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX/2
#define MOD 1000000

set<int> v[112];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	int num=0;
	int mark=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			v[(j+i)%n].insert(mark);
			mark++;
		}
	}

	for(int i=0;i<n;i++){
		while(v[i].size()!=0){
			cout<<*v[i].begin()<<" ";
			v[i].erase(v[i].begin());
		}
		cout<<endl;
	}

	return 0;
}