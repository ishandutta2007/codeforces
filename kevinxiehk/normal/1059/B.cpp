#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	map<int,int[1005]>forge;
	char c;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>c;
			if(c=='#')forge[i][j]=1;
			else forge[i][j]=0;
//			cout<<forge[i][j]<<endl;
		}
	}
	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			if(forge[i-1][j-1]&&forge[i-1][j]&&forge[i][j-1]&&forge[i-1][j+1]&&forge[i+1][j-1]&&forge[i+1][j+1]&&forge[i+1][j]&&forge[i][j+1]){
				forge[i-1][j-1]++;
				forge[i-1][j]++;
				forge[i][j-1]++;
				forge[i-1][j+1]++;
				forge[i+1][j-1]++;
				forge[i+1][j+1]++;
				forge[i+1][j]++;
				forge[i][j+1]++;
	//			cout<<i<<" "<<j<<endl;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
	//		cout<<i<<" "<<j<<" "<<forge[i][j]<<" "<<tryforge[i][j]<<endl;
			if(forge[i][j]==1){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}