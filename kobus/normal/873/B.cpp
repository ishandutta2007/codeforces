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

int num=112345;

int menor[312345];
int maior[312345];
int sumac[312345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	string s;
	cin>>s;
	
	sumac[0]=0;
	sumac[1]=(s[0]=='1')-(s[0]=='0');
	for(int i=1;i<n;i++){
		sumac[i+1]=sumac[i]+(s[i]=='1')-(s[i]=='0');
	}
	for(int i=num-n-1;i<=num+n+1;i++){
		menor[i]=INF;
		maior[i]=-INF;
	}

	for(int i=0;i<=n;i++){
		menor[num+sumac[i]]=min(menor[num+sumac[i]],i);
		maior[num+sumac[i]]=max(maior[num+sumac[i]],i);
	}

	/*for(int i=0;i<=n;i++){
		cout<<sumac[i]<<" ";
	}
	cout<<endl;
	for(int i=num-n-1;i<=num+n+1;i++){
		cout<<i-num<<" "<<menor[i]<<" "<<maior[i]<<endl;
	}*/

	int resp=0;
	for(int i=num-n-1;i<=num+n+1;i++){
		if(maior[i]!=-INF && menor[i]!=INF){
			resp=max(resp,maior[i]-menor[i]);
		}
	}
	cout<<resp<<endl;

	return 0;
}