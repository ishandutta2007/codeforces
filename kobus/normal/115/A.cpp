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

vector<int> are[2123];
int pai[2123];
int size[2123];

void clas(int a){
	for(int i=0;i<are[a].size();i++){
		size[are[a][i]]=size[a]+1;
		clas(are[a][i]);
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>pai[i];
		if(pai[i]!=-1){
			are[pai[i]].pb(i);
		}
	}
	int num=0;
	for(int i=1;i<=n;i++){
		if(pai[i]==-1){
			size[i]=1;
			clas(i);
		}
	}
	for(int i=1;i<=n;i++){
		num=max(num,size[i]);
	}
	cout<<num<<endl;
	

	return 0;
}