#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M1 998244853
#define M2 666623333
#define N 19890604

int i,j,k,n,m,t,sb,f[300500][32];

ll hsh11[300500],hsh12[300500],hsh21[300500],hsh22[300500],it1,it2,cl,cr,t11,t12,t21,t22,pw1[300500],pw2[300500],inv1[300500],inv2[300500];
char s1[300500],s2[300500];
ll ksm1(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M1;}a=a*a%M1;p>>=1;}return res;}
ll ksm2(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M2;}a=a*a%M2;p>>=1;}return res;}

bool gethsh(int cl,int cr,int y){
	t11=hsh11[cr]-hsh11[cl-1];
	t11=(t11%M1+M1)%M1;
	t12=hsh12[cr]-hsh12[cl-1];
	t12=(t12%M2+M2)%M2;
	t11=t11*inv1[cl-1]%M1;
	t12=t12*inv2[cl-1]%M2;
	
	int md=cr-cl+1;
	t21=hsh21[y+md]-hsh21[y];
	t21=(t21%M1+M1)%M1;
	t22=hsh22[y+md]-hsh22[y];
	t22=(t22%M2+M2)%M2;
	t21=t21*inv1[y]%M1;
	t22=t22*inv2[y]%M2;
	return (t11==t21)&&(t12==t22);
}

int chk(int x,int y){
	int l,r,md,ans=0;
	l=1,r=m-y;
	while(l<=r){
		md=(l+r)/2;
		cl=x+1;
		cr=cl+md-1;
		if(gethsh(cl,cr,y)){
			ans=max(ans,md);l=md+1;
		}
		else{
			r=md-1;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>s1+1>>m>>s2+1>>sb;
	it1=it2=1;
	pw1[0]=pw2[0]=inv1[0]=inv2[0]=1;
	for(i=1;i<=100000;i++){
		pw1[i]=pw1[i-1]*N%M1;
		pw2[i]=pw2[i-1]*N%M2;
		inv1[i]=ksm1(pw1[i],M1-2);
		inv2[i]=ksm2(pw2[i],M2-2);
	}
	for(i=1;i<=n;i++){
		hsh11[i]=(hsh11[i-1]+it1*s1[i])%M1;
		hsh12[i]=(hsh12[i-1]+it2*s1[i])%M2;
		it1=it1*N%M1;
		it2=it2*N%M2;
	}
	it1=it2=1;
	for(i=1;i<=m;i++){
		hsh21[i]=(hsh21[i-1]+it1*s2[i])%M1;
		hsh22[i]=(hsh22[i-1]+it2*s2[i])%M2;
		it1=it1*N%M1;
		it2=it2*N%M2;
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=sb;j++){
			if(f[i][j]==m){
				cout<<"YES";return 0;
			}
			f[i+1][j]=max(f[i+1][j],f[i][j]);
			int tmp=chk(i,f[i][j]);
			f[i+tmp][j+1]=max(f[i+tmp][j+1],f[i][j]+tmp);
		}
	}
	cout<<"NO";
}