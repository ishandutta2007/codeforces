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

int b[112][112];

int v[112];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m,n,k;
	cin>>m>>n>>k;

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>b[j][i];
		}
	}
	int score=0;
	int changes=0;

	for(int j=0;j<n;j++){
		v[m-1]=b[j][m-1];
		for(int i=m-2;i>=0;i--){
			v[i]=v[i+1]+b[j][i];
			if(i+k<m)v[i]-=b[j][i+k];
		}
		/*for(int i=0;i<m;i++)cout<<b[j][i]<<" ";
		cout<<endl;
		for(int i=0;i<m;i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;*/
		int maxi=0;
		for(int i=0;i<m;i++){
			maxi=max(maxi,v[i]);
		}
		if(maxi==0)continue;
		int num1=0;
		for(int i=0;i<m;i++){
			if(v[i]==maxi && b[j][i]==1){
				score+=v[i];
				changes+=num1;
				//cout<<v[i]<<" "<<num1<<endl;
				break;
			}
			if(b[j][i]==1)num1++;
		}
	}
	cout<<score<<" "<<changes<<endl;

	return 0;
}