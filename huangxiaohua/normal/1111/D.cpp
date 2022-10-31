#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t,a[66];
ll jc[100500]={1},inv[100500]={1},f[100500]={1},f2[100500],res[55][55],sb=1;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
char s[100500];
int su(int a,int b){a+=b;if(a>=M){a-=M;}return a;}

int main(){
	for(i=1;i<=100005;i++){jc[i]=jc[i-1]*i%M;}
	inv[100005]=ksm(jc[100005],M-2);
	for(i=100004;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	cin>>s+1;
	n=strlen(s+1);
	for(i=1;i<=n;i++){
		if(s[i]>='a'&&s[i]<='z'){s[i]-=('a'-1);}
		else{s[i]-=('A'-1);s[i]+=26;}
		a[s[i]]++;
	}
	for(i=1;i<=52;i++){
		if(!a[i]){continue;}
		for(j=n/2;j>=a[i];j--){
			f[j]=su(f[j],f[j-a[i]]);
		}
		sb=sb*inv[a[i]]%M;
	}
	sb=sb*jc[n/2]%M*jc[n/2]%M;
	for(i=1;i<=52;i++){
		for(j=0;j<=n/2;j++){f2[j]=f[j];}
		for(j=a[i];j<=n/2;j++){
			f2[j]=su(f2[j],M-f2[j-a[i]]);
		}
		res[i][i]=2*f2[n/2]*sb%M;
	}
	for(i=1;i<=52;i++){
		for(j=i+1;j<=52;j++){
			for(k=0;k<=n;k++){f2[k]=f[k];}
			for(k=a[i];k<=n;k++){
				f2[k]=su(f2[k],M-f2[k-a[i]]);
			}
			for(k=a[j];k<=n;k++){
				f2[k]=su(f2[k],M-f2[k-a[j]]);
			}
			res[i][j]=2*f2[n/2]*sb%M;
		}
	}
	cin>>t;
	while(t--){
		cin>>i>>j;i=s[i];j=s[j];
		if(i>j){swap(i,j);}
		cout<<res[i][j]%M<<endl;
	}
}