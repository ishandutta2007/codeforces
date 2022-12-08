#include<bits/stdc++.h>
using namespace std;
int vn[112345];
int vml[112345];
int vmr[112345];
int vmd[112345];
long long vo[112345];
long long vo2[112345];
long long vrp[112345];
long long vrpp[112345];
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>vn[i];
	}
	for(int i=1;i<=m;i++){
		cin>>vml[i]>>vmr[i]>>vmd[i];
	}
	int x,y;
	for(int i=1;i<=k;i++){
		cin>>x>>y;
		vo[x]++;
		vo[y+1]--;
	}
	vo2[1]=vo[1];
	for(int i=2;i<=m;i++){
		vo2[i]=vo2[i-1]+vo[i];
	}
	for(int i=1;i<=m;i++){
		vrp[vml[i]]+=vo2[i]*vmd[i];
		vrp[vmr[i]+1]-=vo2[i]*vmd[i];
	}
	vrpp[1]=vrp[1];
	for(int i=2;i<=n;i++){
		vrpp[i]=vrpp[i-1]+vrp[i];
	}
	for(int i=1;i<=n;i++){
		cout<<vrpp[i]+vn[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}