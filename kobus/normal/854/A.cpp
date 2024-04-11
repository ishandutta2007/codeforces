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


bool prop(int a,int b){
	return a<b;
}

bool irr(int a,int b){
	for(int i=2;i<1002;i++){
		if(a%i==0 && b%i==0)return 0;
	}
	return 1;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	int resp=0;

	int a,b;

	for(int i=0;i<n;i++){
		if(prop(i,n-i)&& irr(i,n-i)){
			a=i;b=n-i;
		}
	}

	cout<<a<<" "<<b<<endl;
	//cout<<prop(5,7)<<" "<<irr(5,7)<<endl;



	return 0;
}