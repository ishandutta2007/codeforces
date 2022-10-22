#include<iostream>
#include<vector>
using namespace std;
string flag[1000];
vector<int> col[1000];
int por[1000][1000]={0};
int main()
{
	int n,m,sum=0;
	char ber;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>flag[i];
	}
	for(int i=0;i<m;i++){
		ber=flag[0][i];
		col[i].push_back(0);
		for(int j=0;j<n;j++){
			if(flag[j][i]!=ber){
				ber=flag[j][i];
				col[i].push_back(j-1);
				col[i].push_back(j);
			}
		}
		col[i].push_back(n-1);
	}
	int sh,t,tam,k,poo=0;
	for(int i=0;i<m;i++){	
		for(int j=0;j+4<col[i].size();j+=2){
			if(col[i][j+1]-col[i][j]>=col[i][j+3]-col[i][j+2] && col[i][j+5]-col[i][j+4]>=col[i][j+3]-col[i][j+2]){
				if ( por[col[i][j+1]-(col[i][j+3]-col[i][j+2])][i]==0){
					sh=col[i][j+1]-(col[i][j+3]-col[i][j+2]);
					tam=col[i][j+3]+(col[i][j+3]-col[i][j+2])+1;
					t=0;
					int sa=i+1;
					while(sa<m){
						t=0;
						for(int i2=sh;i2<=tam;i2++){
							if(flag[i2][sa]!=flag[i2][i]){
								t=1;
								break;
							}
						}
						if(t==0){
							por[sh][sa]=1;
							sa++;
						}
						else
							break;
					}
					sum+=((sa-i)*(sa-i-1))/2+(sa-i);	
				}
			}
		}
	}
	cout<<sum;
}