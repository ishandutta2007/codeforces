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
#define int long long

pair<char,int> v[512345];

int t[2][11];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i].f>>v[i].s;
	}
	int num=0;
	for(int i=0;i<n;i++){
		if(v[i].f=='|')num|=v[i].s;
		if(v[i].f=='&')num&=v[i].s;
		if(v[i].f=='^')num^=v[i].s;
	}
	for(int i=0;i<10;i++){
		t[0][i]=(num>>i)%2;
	}
	num=1023;
	for(int i=0;i<n;i++){
		if(v[i].f=='|')num|=v[i].s;
		if(v[i].f=='&')num&=v[i].s;
		if(v[i].f=='^')num^=v[i].s;
	}
	for(int i=0;i<10;i++){
		t[1][i]=(num>>i)%2;
	}
	for(int i=0;i<10;i++){
		//cout<<t[0][i]<<" "<<t[1][i]<<endl;
	}

	int ou=0;
	int xou=0;
	int e=1023;
	for(int i=0;i<10;i++){
		if(t[0][i]==1 && t[1][i]==1){
			ou+=(1<<i);
		}
		if(t[0][i]==1 && t[1][i]==0){
			xou+=(1<<i);
		}
		if(t[0][i]==0 && t[1][i]==0){
			//cout<<(1<<i)<<endl;
			e-=(1<<i);
		}
	}
	cout<<3<<endl;
	cout<<"| "<<ou<<endl;
	cout<<"^ "<<xou<<endl;
	cout<<"& "<<e<<endl;


	return 0;
}