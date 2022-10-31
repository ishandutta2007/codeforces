#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n;
char sb[100500];
ll a[666],b[666],sum,t;

int main(){
	scanf("%d%lld%s",&n,&t,sb+1);
	a[1]=1;
	for(i=2;i<=26;i++){a[i]=a[i-1]*2;}
	for(i=1;i<=n;i++){b[sb[i]-'a'+1]++;}
	for(i=1;i<=26;i++){sum+=b[i]*a[i];}
	sum-=2*a[sb[n-1]-'a'+1];
	b[sb[n]-'a'+1]--;
	b[sb[n-1]-'a'+1]--;
	for(i=1;i<=26;i++){a[i]*=2;}
	sum-=t;
	for(i=26;i>=1;i--){
		while(b[i]){
			if(sum>=a[i]){sum-=a[i];b[i]--;}
			else{break;}
		}
	}
	if(sum){puts("No");}else{puts("Yes");}
}