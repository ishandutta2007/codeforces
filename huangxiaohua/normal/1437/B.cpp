#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,t,res,res2,l,r;
char sb[200500];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		cin>>sb+1;
		res=res2=0;
		for(i=2;i<=n;i++){
			if(sb[i]=='1'&&sb[i-1]=='1'){res++;}
			if(sb[i]=='0'&&sb[i-1]=='0'){res2++;}
		}
		printf("%d\n",max(res,res2));
	}
}