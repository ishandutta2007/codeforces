#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007

int v1[212345];
pii v2[212345];

int resp[212345];

bool fun(int a,int b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>v1[i];
	}
	for(int i=0;i<m;i++){
		cin>>v2[i].f;
		v2[i].s=i;
	}
	sort(v2,v2+m);
	sort(v1,v1+m,fun);

	for(int i=0;i<m;i++){
		resp[v2[i].s]=v1[i];
	}
	for(int i=0;i<m;i++){
		cout<<resp[i]<<" ";
	}
	cout<<endl;


	return 0;
}