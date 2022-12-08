#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 1123
#define INF LLONG_MAX
#define MOD 32416187567

int pos[1123456];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			x--;
			pos[x]=i;
		}
		int mini=pos[0];
		int maxi=pos[0];
		for(int i=0;i<n;i++){
			mini=min(mini,pos[i]);
			maxi=max(maxi,pos[i]);
			if(maxi-mini==i)cout<<1;
			else cout<<0;
		}
		cout<<endl;
	}

	return 0;
}