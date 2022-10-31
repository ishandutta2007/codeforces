#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,pos[10005000],sb,a[10005000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		sb=n*m-3;
		for(i=1;i<=k;i++){
			cin>>a[i];
			a[i]=k+1-a[i];
			pos[a[i]]=i;
		}
		for(i=1;i<=k;i++){
			//printf("a%d %d %d\n",i,pos[i],sb+i-1);
			if(pos[i]>sb+i-1){
				cout<<"TIDAK\n";goto aaa;
			}
		}
		cout<<"YA\n";
		aaa:;
	}
}