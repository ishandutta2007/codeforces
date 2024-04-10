#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;

//static char ss[1<<17],*A=ss,*B=ss;
//char gc(){
//    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
//}
//int read(){
//    int f=1,c; 
//	while (c=gc(),c<48||c>57) if (c=='-') f=-1; 
//	int x=c-'0';
//    while(c=gc(),c>47&&c<58) x=x*10+c-'0'; 
//	return f>0?x:-x;
//}


const LL P=998244353;
const int INF=1e9; 
const int N=2e5+10;
void init(){
	return;
}

int jc[110];
int c[110][110];
int f[110][110][110];
bool vis[110][110][110];
LL p;
int sol(int n,int m,int k){
	//cout<<n<<" "<<m<<" "<<k<<endl;
	if(vis[n][m][k]) return f[n][m][k];
	vis[n][m][k]=1;
	f[n][m][k]=0;
	if(n==0){
		if(k==0) return f[n][m][k]=1;
		else return f[n][m][k]=0;
	}
	if(m==0){
		if(k==0) return f[n][m][k]=1;
		else return f[n][m][k]=0;
	}
	if(m==1){
		if(k==1) return f[n][m][k]=jc[n];
		else return f[n][m][k]=0;
	}
	if(k>0&&m+k-1>n) return 0;
	if(m+k-1>n){
		return f[n][m][k]=jc[n];
	}
	__int128_t re=0,ss=0;
	for(int i=1;i<=n;++i){
		re=0;
		for(int k1=0;k1<=k;++k1)
			re+=(__int128_t)sol(i-1,m-1,k1)*sol(n-i,m-1,k-k1);
		ss+=(__int128_t)c[n-1][i-1]*re;
	}
	f[n][m][k]=ss%p;
	//cout<<n<<" "<<m<<" "<<k<<" "<<f[n][m][k]<<endl;
	return f[n][m][k];
}
int n,m,k;
void MAIN(){
	cin>>n>>m>>k>>p;
	c[0][0]=1;
	jc[0]=1;
	for(LL i=1;i<=100;++i) jc[i]=(LL)jc[i-1]*i%p;
	for(int i=1;i<=100;++i){
		c[i][0]=1;
		for(int j=1;j<=i;++j){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			if(c[i][j]>=p) c[i][j]-=p;
		}
	}
	
	cout<<sol(n,m,k)<<endl;
	return;
}

int main(){
	init();
	int ttt=1;//scanf("%d",&ttt); 
	while(ttt--) MAIN();
	return 0;
}
/*
100 50 50 1000000007
*/