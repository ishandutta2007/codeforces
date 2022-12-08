#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007

int n;
vector<int>are[112345];
int len[112345];
double prob[112345];
double resp;

void dfsl(int a){
	for(int i=0;i<are[a].size();i++){
		if(len[are[a][i]]==-1){
			len[are[a][i]]=len[a]+1;
			dfsl(are[a][i]);
		}
	}
}

void dfsp(int a){
	for(int i=0;i<are[a].size();i++){
		if(prob[are[a][i]]==-1){
			if(a==1){
				prob[are[a][i]]=prob[a]/(are[a].size());
			}
			else prob[are[a][i]]=prob[a]/(are[a].size()-1);
			dfsp(are[a][i]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	if(n==1){
		cout<<0.<<endl;
		return 0;
	}
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		are[a].pb(b);
		are[b].pb(a);
	}
	for(int i=1;i<=n;i++){
		len[i]=-1;
		prob[i]=-1;
	}
	len[1]=0;prob[1]=1;
	dfsl(1);
	dfsp(1);

	for(int i=1;i<=n;i++){
		if(are[i].size()==1){
			resp+=len[i]*prob[i];
		}
	}

	cout.precision(15);
 	cout.setf(ios::fixed);

 	cout<<resp<<endl;
	
	return 0;
}