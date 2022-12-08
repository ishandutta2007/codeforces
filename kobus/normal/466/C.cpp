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
#define INF INT_MAX;
#define MOD 1000000

int v[512345];
int sumac[512345];
int qtos[512345];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	int sumtot=0;
	for(int i=0;i<n;i++){
		cin>>v[i];
		sumtot+=v[i];
	}
	if(sumtot%3!=0){
		cout<<0<<endl;
		return 0;
	}
	sumtot=sumtot/3;
	sumac[0]=v[0];
	for(int i=1;i<n;i++){
		sumac[i]=sumac[i-1]+v[i];
	}
	int a1=sumtot;
	int a2=2*sumtot;

	int mark=0;
	for(int i=1;i<n-1;i++){
		if(sumac[i-1]==a1)mark++;
		qtos[i]=mark;
	}

	int resp=0;
	for(int i=1;i<n-1;i++){
		if(sumac[i]==a2)resp+=qtos[i];
	}
	cout<<resp<<endl;





	return 0;
}