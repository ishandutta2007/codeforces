#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 112345
#define INF INT_MAX/2
#define MOD 1000000007

int v[1123456];

int ma[1123];
int maux[1123];



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;

	if(n>m){
		cout<<"YES"<<endl;
		return 0;
	}

	for(int i=0;i<n;i++){
		cin>>v[i];
		v[i]%=m;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ma[j]==1){
				maux[(j+v[i])%m]=1;
			}
		}
		for(int i=0;i<m;i++)ma[i]=ma[i]||maux[i];
		ma[v[i]]++;
	}

	if(ma[0]){
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;

	return 0;
}