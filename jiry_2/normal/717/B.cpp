#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,c0,c1,C[70][50010];
const int N=60,M=40000;
struct atom{
	long long w;
	int num;
}A[50];
int len;
int check(long long lim){
	int now=min(1ll*n,lim/c1);
	for (int i=1;i<=N;i++){
		int j=0;
		while (1ll*i*c0+1ll*j*c1<=lim&&now<n){
			now=min(n,now+C[i][j]); j++;
		}
	}
	return now;
}
int compare(atom k1,atom k2){
	return k1.w<k2.w;
}
long long calc(long long lim){
//	cout<<"asd "<<lim<<endl;
	long long ans=1ll*n*(c0+c1); int len=0;
	int k=lim/c1; A[++len]=(atom){1ll*k*c1,1};
	int rem=n; 
	k--; if (k>=0) ans+=1ll*(k+1)*k/2*c1,rem-=k+1;
	for (int i=1;i<=N;i++){
		int j=0;
		while (1ll*i*c0+1ll*j*c1<=lim) j++;
		j--; if (j<0) continue;
		A[++len]=(atom){1ll*i*c0+1ll*j*c1,C[i][j]}; j--;
		while (j>=0){
			ans+=(1ll*i*c0+1ll*j*c1)*C[i][j]; rem-=C[i][j]; j--;
		}
	}
//	cout<<rem<<endl; 
	sort(A+1,A+len+1,compare);
	for (int i=1;i<=len;i++){
		int k=min(rem,A[i].num);
		ans+=1ll*k*A[i].w; rem-=k;
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&c0,&c1);
	if (c0<c1) swap(c0,c1); n--;
	if (n==0){
		cout<<0<<endl; return 0;
	}
	if (c1==0){
		cout<<1ll*n*c0<<endl; return 0;
	}
	for (int i=0;i<=M;i++) C[0][i]=1;
	for (int i=1;i<=N;i++){
		C[i][0]=1;
		for (int j=1;j<=M;j++) C[i][j]=min(C[i-1][j]+C[i][j-1],n);
	}
	long long l=0,r=1e17,ans=0;
	while (l<r){
		long long mid=l+r>>1;
		if (check(mid)>=n){
			ans=mid; r=mid;
		} else l=mid+1;
	}
//	cout<<ans<<endl;
	cout<<calc(ans)<<endl;
	return 0;
}