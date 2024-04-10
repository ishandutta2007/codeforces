#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,r1=-1,r2;
char s1[10050],s2[10050];
int main(){
	cin>>n>>m;
	cin>>s1+1>>s2+1;
	for(i=1;i+n-1<=m;i++){
		k=0;
		for(j=1;j<=n;j++){
			k+=(s1[j]==s2[i+j-1]);
		}
		if(k>r1){
			r1=k;r2=i;
		}
	}
	cout<<n-r1<<endl;
	for(i=1;i<=n;i++){
		if(s1[i]!=s2[i+r2-1]){
			cout<<i<<' ';
		}
	}
}