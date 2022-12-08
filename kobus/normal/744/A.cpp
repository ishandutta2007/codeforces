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
#define INF LLONG_MAX/4
#define MOD 1000000007

int gov[1123];
vector<int> are[1123];

int comp[1123];
int dfs(int a){
	for(int i=0;i<are[a].size();i++){
		if(comp[are[a][i]]==-1){
			comp[are[a][i]]=comp[a];
			dfs(are[a][i]);
		}
	}
}

int comps[1123];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m,k;
	cin>>n>>m>>k;

	for(int i=0;i<k;i++){
		cin>>gov[i];
		gov[i]--;
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		are[a].pb(b);
		are[b].pb(a);
	}

	for(int i=0;i<n;i++)comp[i]=-1;

	for(int i=0;i<k;i++){
		comp[gov[i]]=i;
		dfs(gov[i]);
	}

	int resto=0;
	for(int i=0;i<n;i++){
		if(comp[i]>=0)comps[comp[i]]++;
		else resto++;
	}

	sort(comps,comps+k);

	comps[k-1]+=resto;
	int resp=0;
	for(int i=0;i<k;i++){
		//cout<<comps[i]<<endl;
		resp+=comps[i]*(comps[i]-1)/2;
	}
	cout<<resp-m<<endl;

	return 0;
}