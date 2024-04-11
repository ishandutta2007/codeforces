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

int vi[112345];
int vf[112345];

bool level[112345];

vector<int> are[112345];
vector<int> arep[112345];

void makeare(int a,int p){
	for(int i=0;i<arep[a].size();i++){
		if(arep[a][i]!=p){
			level[arep[a][i]]=!level[a];
			are[a].pb(arep[a][i]);
			makeare(arep[a][i],a);
		}
	}
}

vector<int> answer;

bool par[212345];
bool imp[212345];

void getvalue(int a){
	if(level[a] && par[a])vi[a]=!vi[a];
	if(!level[a] && imp[a])vi[a]=!vi[a];
}

void propagate(int a){
	for(int i=0;i<are[a].size();i++){
		par[are[a][i]]=par[a];
		imp[are[a][i]]=imp[a];
	}
}

void getsans(int a){
	getvalue(a);
	if(vi[a]!=vf[a]){
		answer.pb(a);
		if(level[a]){
			par[a]=!par[a];
		}
		else{
			imp[a]=!imp[a];
		}
	}
	propagate(a);
	for(int i=0;i<are[a].size();i++){
		getsans(are[a][i]);
	}
}



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		arep[a].pb(b);
		arep[b].pb(a);
	}

	makeare(1,0);

	for(int i=1;i<=n;i++){
		cin>>vi[i];
	}
	for(int i=1;i<=n;i++){
		cin>>vf[i];
	}

	getsans(1);

	cout<<answer.size()<<endl;
	for(int i=0;i<answer.size();i++){
		cout<<answer[i]<<endl;
	}


	return 0;
}