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
#define MOD 1000000007

vector<int> are[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;
	set<int> r;
	set<int> v;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		are[a].pb(b);
		are[b].pb(a);
	}
	r.insert(1);
	while(r.size()>0){
		int at=*r.begin();
		cout<<at<<" ";
		r.erase(at);
		v.insert(at);
		for(int i=0;i<are[at].size();i++){
			if(v.find(are[at][i])==v.end())
				r.insert(are[at][i]);
		}
	}
	cout<<endl;


	return 0;
}