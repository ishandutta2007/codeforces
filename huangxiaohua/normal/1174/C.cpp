#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,res[100500],it;
vector<int> v;

int main(){
	for(i=2;i<=100000;i++){
		if(!res[i]){
			k++;
			for(j=i;j<=100000;j+=i){res[j]=k;}
		}
	}
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		printf("%d ",res[i]);
	}
}