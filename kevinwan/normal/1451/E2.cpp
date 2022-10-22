#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 2e5+10;
const ll mod = 1e9+7;

int a[mn];
int ra[mn];

int main()
{
	//cin.tie(0);
	//cin.sync_with_stdio(0);
	int n;
	cin>>n;
	a[1]=-1;
	for(int i=2;i<=n;i++){
		cout<<"XOR 1 "<<i<<endl;
		int r;
		cin>>r;
		a[i]=r;
		if(ra[a[i]]&&a[1]==-1){
			int j=ra[a[i]];
			cout<<"OR "<<i<<" "<<j<<endl;
			cin>>r;
			a[1]=r^a[i];
		}
		ra[a[i]]=i;
		if(r==0&&a[1]==-1){
			cout<<"OR 1 "<<i<<endl;
			cin>>r;
			a[1]=r;
		}
	}
	if(a[1]==-1){
		int aa,b;
		cout<<"OR 1 "<<ra[1]<<endl;
		cin>>aa;
		cout<<"OR 1 "<<ra[2]<<endl;
		cin>>b;
		a[1]=aa&b;
	}
	for(int i=2;i<=n;i++)a[i]^=a[1];
	cout<<"! ";
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<endl;
}