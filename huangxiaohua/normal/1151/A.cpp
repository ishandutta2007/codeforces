#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,a[5]={0,2,19,6},res,tmp;
char sb[150];
int main(){
	cin>>n;
	cin>>sb+1;
	res=114514;
	for(i=1;i+3<=n;i++){
		tmp=0;
		for(j=0;j<=3;j++){
			tmp+=min(abs(sb[i+j]-'A'-a[j]),26-abs(sb[i+j]-'A'-a[j]));
		}res=min(res,tmp);
	}
	
	printf("%d",res);
}