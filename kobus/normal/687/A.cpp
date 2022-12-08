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

vector<int> are[112345];
int cara[112345];
int n,m;

void find(int a){
	for(int i=0;i<are[a].size();i++){
		if(cara[are[a][i]]==0){
			if(cara[a]==1){
				cara[are[a][i]]=2;
			}
			else cara[are[a][i]]=1;
			find(are[a][i]);
		}
	}
}

bool check(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<are[i].size();j++){
			if(cara[i]==cara[are[i][j]])return 0;
		}
	}
	return 1;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		are[a].pb(b);
		are[b].pb(a);
	}

	for(int i=1;i<=n;i++){
		if(cara[i]==0){
			cara[i]=1;
			find(i);
		}
		//cout<<i<<" "<<cara[i]<<endl;
	}

	if(!check()){
		cout<<-1<<endl;
		return 0;
	}

	int c1=0,c2=0;
	for(int i=1;i<=n;i++){
		if(cara[i]==1)c1++;
		if(cara[i]==2)c2++;
		//cout<<i<<" "<<cara[i]<<endl;
	}
	cout<<c1<<endl;
	for(int i=1;i<=n;i++){
		if(cara[i]==1){
			cout<<i<<" ";
		}
	}
	cout<<endl<<c2<<endl;
	for(int i=1;i<=n;i++){
		if(cara[i]==2){
			cout<<i<<" ";
		}
	}
	cout<<endl;


	return 0;
}