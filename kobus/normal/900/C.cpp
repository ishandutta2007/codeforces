#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF INT_MAX/2
#define MOD 1000000

int v[112345];
int d[112345];
bool r[112345];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	int m=0;
	int mi=0;
	int sm=0;
	int smi=0;

	for(int i=0;i<n;i++){
		if(v[i]>m)r[i]=true;
		if(v[i]<m && v[i]>sm){
			d[mi]++;
		}
		if(v[i]>sm){
			sm=v[i];
			smi=i;
		}
		if(sm>m){
			swap(sm,m);
			swap(smi,mi);
		}
	}

	int maxi=-INF;

	for(int i=0;i<n;i++){
		d[i]-=r[i];
		maxi=max(maxi,d[i]);
	}

	int minel=INF;

	for(int i=0;i<n;i++){
		if(d[i]==maxi && v[i]<minel){
			minel=v[i];
		}
	}

	cout<<minel<<endl;

	return 0;
}