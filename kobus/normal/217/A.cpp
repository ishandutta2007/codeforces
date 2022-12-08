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
#define INF INT_MAX;
#define MOD 1000000

pii v[112];
vector<int> are[112];
int comp[112];

void calc(int u){
	for(int i=0;i<are[u].size();i++){
		if(comp[are[u][i]]==0){
			comp[are[u][i]]=comp[u]+1;
			calc(are[u][i]);
		}
	}
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++)cin>>v[i].f>>v[i].s;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j && (v[i].f==v[j].f||v[i].s==v[j].s)){
				are[i].pb(j);
			}
		}
	}

	int num=0;

	for(int i=0;i<n;i++){
		if(comp[i]==0){
			num++;
			comp[i]=num;
			calc(i);
		}
	}

	cout<<num-1<<endl;

	return 0;
}