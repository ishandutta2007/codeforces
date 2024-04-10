#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[666];
string res,r1,s1[666];
char s[105][105];

bool chk(int x,int y){
	int i,j;
	for(i=1;i<=m;i++){
		if(s[x][i]!=s[y][m+1-i])return 0;
	}
	return 1;
}

bool chk2(int x){
	int i,j;
	for(i=1;i<=m;i++){
		if(s[x][i]!=s[x][m+1-i])return 0;
	}
	return 1;
}

int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>s[i]+1;
		for(j=1;j<=m;j++){
			s1[i]+=s[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			//printf("nmsl%d %d\n",i,j);
			if(a[i]||a[j])continue;
			if(chk(i,j)){
				a[i]=a[j]=1;
				r1=s1[i]+r1+s1[j];
			}
		}
	}
	
	for(i=1;i<=n;i++){
		if(!chk2(i))continue;
		memset(a,0,sizeof(a));
		a[i]=1;
		res=s1[i];
		for(j=1;j<=n;j++){
			for(k=j+1;k<=n;k++){
				if(a[k]||a[j])continue;
				if(chk(j,k)){
					res=s1[j]+res+s1[k];
					a[j]=a[k]=1;
				}
			}
		}
		if(res.size()>r1.size()){
			r1=res;
		}
	}
	cout<<r1.size()<<endl;
	cout<<r1;
}