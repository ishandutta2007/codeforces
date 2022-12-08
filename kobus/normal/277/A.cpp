#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
//#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF LLONG_MAX;
#define MOD 1000000

vector<int> are[1123];

int comp[1123];

int label(int a){
	for(int i=0;i<are[a].size();i++){
		if(comp[are[a][i]]==0){
			comp[are[a][i]]=comp[a];
			label(are[a][i]);
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,l;
	cin>>n>>l;

	bool alzero=true;

	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		if(num!=0)alzero=false;
		for(int j=0;j<num;j++){
			int lan;
			cin>>lan;
			are[i].pb(lan+101);
			are[lan+101].pb(i);
		}
	}
	if(alzero){
		cout<<n<<endl;
		return 0;
	}
	int mark=1;
	for(int i=0;i<n;i++){
		if(comp[i]==0){
			comp[i]=mark;
			label(i);
			mark++;
		}
	}
	cout<<mark-2<<endl;

	return 0;
}