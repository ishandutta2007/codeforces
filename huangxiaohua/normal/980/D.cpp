#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res[5050],a[5050],p[10050],b[5050],it;
unordered_map<int,int> mp;

int main(){
	srand(time(0));
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=2;i<=10000;i++){
		if(!p[i]){
			for(j=i;j<=10000;j+=i){
				p[j]=1;
			}
			for(j=1;j<=n;j++){
				while(a[j]&&!(a[j]%(i*i))){a[j]=a[j]/i/i;}
			}
		}
	}
	for(i=1;i<=n;i++){
		if(a[i]&&!mp[a[i]]){mp[a[i]]=++it;}
		a[i]=mp[a[i]];
	}
	for(i=1;i<=n;i++){
		k=0;
		memset(b,0,sizeof(b));
		for(j=1;j<=n;j++){
			if(!b[a[j]]){k++;}b[a[j]]++;
			if(j>=i){
				res[k-(k>1&&b[0])]++;b[a[j-i+1]]--;if(!b[a[j-i+1]]){k--;}
			}
		}
	}
	for(i=1;i<=n;i++){
		printf("%d ",res[i]);
	}
}