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


//price and qte and type
vector<pair<pii,int>> pqt;
int price[112345];
int qte[112345];

map<int,int> pos;

bool ord(pair<pii,int> a,pair<pii,int> b){
	if(a.f.f!=b.f.f)return a.f.f<b.f.f;
	return a.s<b.s;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>qte[i];
	}
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	for(int i=0;i<n;i++)pqt.pb(mp(mp(price[i],qte[i]),i));
	sort(pqt.begin(),pqt.end(),ord);
	for(int i=0;i<n;i++){
		pos[pqt[i].s]=i;
	}
	int lucro=0;
	int ca=0;
	for(int i=0;i<m;i++){
		int type,number;
		cin>>type>>number;
		type--;
		//cout<<i<<endl;
		if(qte[type]>0){
			//cout<<"entrou "<<qte[type]<<endl;
			int bought=min(qte[type],number);
			number-=bought;
			qte[type]-=bought;
			pqt[pos[type]].f.s-=bought;
			//cout<<"entrou 2 "<<qte[type]<<endl;
			lucro+=bought*price[type];
		}
		while(ca<n && number>0){
			//cout<<"ca "<<ca<<" "<<pqt[ca].f.s<<endl;
			int bought=min(pqt[ca].f.s,number);
			pqt[ca].f.s-=bought;
			number-=bought;
			qte[pqt[ca].s]-=bought;
			//cout<<pqt[ca].f.s<<" "<<qte[pqt[ca].s]<<endl;
			lucro+=bought*pqt[ca].f.f;
			//cout<<bought<<" "<<lucro<<endl;
			if(pqt[ca].f.s==0)ca++;
		}
		if(number>0)cout<<0<<endl;
		else cout<<lucro<<endl;
		lucro=0;
	}


	return 0;
}