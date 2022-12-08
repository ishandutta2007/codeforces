#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MAXN 1123
#define INF (int)1.5e12
#define INFF LLONG_MAX/2
#define eps 1e-4


int n,m;
int v[312345];
int vv[312345];

bool da(int x){
	//cout<<"X "<<x<<endl;
	for(int i=0;i<n;i++){
		if(i==0){
			vv[i]=v[i];
			if(vv[i]+x>=m)vv[i]=0;
			//cout<<vv[i]<<endl;
			continue;
		}
		int last=vv[i-1];
		if(last<v[i])last+=m;
		if(v[i]+x>=last)vv[i]=last%m;
		else{
			vv[i]=v[i];
			if(vv[i]<vv[i-1])return 0;
		}
		//cout<<vv[i]<<endl;
	}
	return 1;
}

int bb(){
	int com=0,fim=m,meio,best=-1;
	while(com<=fim){
		meio=(com+fim)/2;
		if(da(meio)){
			best=meio;
			fim=meio-1;
		}
		else com=meio+1;
	}
	return best;
}

int32_t main(){
	cout<<setprecision(5)<<fixed;

	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>v[i];
	cout<<bb()<<endl;

    return 0;
}