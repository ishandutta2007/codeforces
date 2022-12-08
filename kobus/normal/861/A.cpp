#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000

int mdc(int a,int b){
	if(b>a)return mdc(b,a);
	if(b==0) return a;
	return mdc(b,a%b);
}

int tt(int a){
	int resp=1;
	for(int i=0;i<a;i++)resp*=10;
	return resp;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,k;
	cin>>n>>k;

	cout<<n/mdc(n,tt(k));

	for(int i=0;i<k;i++){
		cout<<"0";
	}

	cout<<endl;





	return 0;
}