#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 1000000007
#define INF INT_MAX - 5000
 
int t[112345];
int c[112345];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<m;i++){
		cin>>t[i];
	}
	sort(c,c+n);
	sort(t,t+m);

	int mt=1;

	int resp=0;

	for(int i=0;i<n;i++){
		while(mt<m-1 && t[mt]<c[i]){
			mt++;
		}
		if(m==1){
			resp=max(resp,abs(t[0]-c[i]));
			continue;
		}
		resp=max(resp,min(abs(t[mt]-c[i]),abs(t[mt-1]-c[i])));
	}

	cout<<resp<<endl;

	return 0;
}