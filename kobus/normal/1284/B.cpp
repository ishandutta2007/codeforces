#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 1123456
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define double long double 
#define int long long

int bit[MAXN];

void upd(int a, int x){
	if(a==0)return;
	for(int i=a;i<MAXN;i+=(i&-i))bit[i]+=x;
}

int get(int a){
	int resp=0;
	for(int i=a;i>0;i-=(i&-i))resp+=bit[i];
	return resp;
}
																																																																																	

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	//minimo e maximo
	vector<pii> rel;
	int tot=n;
	int resp=0;
 	for(int i=0;i<n;i++){
 		int m;
 		cin>>m;
 		vector<int> at;
 		int last=INF;
 		int mini=INF;
 		int maxi=0;
 		bool tem=0;
 		for(int i=0;i<m;i++){
 			int x;
 			cin>>x;
 			if(x>last)tem=1;
 			maxi=max(maxi,x);
 			mini=min(mini,x);
 			last=x;
 		}
 		if(!tem)rel.pb(mp(mini+2,maxi+2));
 	}
 	/*int resp2=0;
 	for(int i=0;i<rel.size();i++){
 		for(int j=0;j<rel.size();j++){
 			if(rel[j].s<=rel[i].f)resp2++;
 		}
 	}
 	cout<<n*n-resp2<<endl;*/

 	for(auto x:rel)upd(x.s,1);
 	for(auto x:rel){
 		resp+=get(x.f);
 	}
 	cout<<n*n-resp<<endl;
	
	return 0;
}