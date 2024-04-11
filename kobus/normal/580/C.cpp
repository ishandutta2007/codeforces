#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define f first
#define s second
#define pb push_back
#define MAXN 1000000007
#define INF INT_MAX

int n,c;
vector<int> are[112345];
int cat[112345];
int visited[112345];

int dpfs(int ele,int cocat){
	//cout<<ele<<" "<<cocat<<" "<<cat[ele]<<endl;
	visited[ele]=1;
	if(cocat==c && cat[ele]){
		return 0;
	}
	if(are[ele].size()==1 && ele!=1){
		return 1;
	}
	int resp=0;
	for(int i=0;i<are[ele].size();i++){
		if(!visited[are[ele][i]]){
			if(cat[ele]){
				resp+=dpfs(are[ele][i],cocat+1);
			}
			else{
				resp+=dpfs(are[ele][i],0);
			}
		}
	}
	return resp;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>c;

	for(int i=1;i<=n;i++){
		cin>>cat[i];
	}

	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		are[x].pb(y);
		are[y].pb(x);
	}
	cout<<dpfs(1,0)<<endl;
	

	
	return 0;
}