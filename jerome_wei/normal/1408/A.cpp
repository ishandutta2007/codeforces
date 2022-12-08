#include<bits/stdc++.h>
using namespace std;
int n;
bool f[110][3][3];

void Main(){
	cin >> n;
	vector<int> a[3];
	for(int i=0;i<3;i++)a[i].resize(n);
	for(int i=0;i<n;i++)cin >> a[0][i];
	for(int i=0;i<n;i++)cin >> a[1][i];
	for(int i=0;i<n;i++)cin >> a[2][i];
	memset(f,0,sizeof f);
	for(int i=0;i<3;i++)f[0][i][i]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					if(a[k][i]!=a[l][i-1]){
						f[i][j][k] |= f[i-1][j][l];
					}
				}
			}
		}
	}
	int curi=0,curj=0;
	for(int i=0;i<3;i++)for(int j=0;j<3;j++){
		if(f[n-1][i][j] && a[i][0] != a[j][n-1]){
			curi=i,curj=j;
		}
	}
	vector<int> ans;
	for(int i=n-1;~i;i--){
		// cout << i << ":" << curj << endl;
		ans.push_back(a[curj][i]);
		if(i==0)break;
		for(int prej=0;prej<3;prej++){
			if(f[i-1][curi][prej] && a[prej][i-1]!=a[curj][i]){
				curj = prej;break;
			}
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto p:ans)cout << p << " ";
	puts("");
}

int main()
{
	int T;cin >> T;
	while(T--){
		Main();
	}
}