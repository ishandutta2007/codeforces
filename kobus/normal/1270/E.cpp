#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 5123
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define double long double 
#define int long long

vector<pii> pontos;

bool tudopar(){
	for(pii p:pontos){
		if((p.f+p.s)%2)return 0;
	}
	return 1;
}

bool tudoimpar(){
	for(pii p:pontos){
		if(((p.f+p.s)%2)==0)return 0;
	}
	return 1;
}

void despar(){
	for(int i=0;i<pontos.size();i++){
		pontos[i]=mp((pontos[i].f-pontos[i].s)/2,(pontos[i].f+pontos[i].s)/2);
	}
}

void desimpar(){
	for(int i=0;i<pontos.size();i++){
		pontos[i].f++;
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		pontos.pb(mp(a,b));
	}

	while(tudopar()||tudoimpar()){
		if(tudoimpar())desimpar();
		if(tudopar())despar();
	}
	int resp=0;
	for(int i=0;i<n;i++){
		if((pontos[i].f+pontos[i].s)%2)resp++;
	}
	cout<<resp<<endl;
	for(int i=0;i<n;i++){
		if((pontos[i].f+pontos[i].s)%2)cout<<i+1<<" ";
	}
	cout<<endl;


	return 0;
}