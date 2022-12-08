#include<bits/stdc++.h>
using namespace std;
const int N=2010;
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
int a[N][N];
int f[N][N];
int n;

inline void init(int n){
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		f[i][0]=mul(f[i-1][0],i);
		for(int j=1;j<=i;j++){
			f[i][j]=add(mul(j>=2?f[i-1][j-2]:0,j-1),mul(f[i-1][j-1],i-j));
		}
	}
}
struct Bit{
#define lowbit(x) ((x) & (-x))
int t[N];
inline void add(int a){
	if(a==0)return ;
	for(;a<=n;a+=lowbit(a))t[a]++;
}
inline int qry(int x){
	int ans=0;
	for(;x;x-=lowbit(x))ans+=t[x];
	return ans;
}
inline void clear(){
	for(int i=1;i<=n;i++)t[i]=0;
}
}T1,T2;
int main()
{
	int ans=0;
	cin >> n;init(n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++){
		T1.clear(),T2.clear();
		int way=qpow(f[n][n],n-i);
		vector<bool> vis1(n+1,1),vis2(n+1,1);
		vis1[a[i][n]]=0;int temp=0;
		for(int j=n;j;j--){
			vis2[a[i-1][j]]=0;
			vis1[a[i][j]]=0;
			T1.add(a[i][j]);
			if(!vis2[a[i][j]])T2.add(a[i][j]),++temp;
			if(!vis1[a[i-1][j]])T2.add(a[i-1][j]),++temp;
			int sum1=T1.qry(a[i][j]-1),sum2=T2.qry(a[i][j]-1);
			if(!vis1[a[i-1][j]] && a[i-1][j] < a[i][j]) sum1--,sum2--;
			if(temp==0){
				ans=add(ans,mul(way,mul(sum1,f[n-j][0])));
			}else{
				ans=add(ans,mul(way,mul(sum1-sum2,f[n-j][temp-(!vis1[a[i-1][j]])])));
				ans=add(ans,mul(way,mul(sum2,f[n-j][temp-1-(!vis1[a[i-1][j]])])));
			}
			// if(ans>0)cout << i << " " << j << " " << sum1 << " " << sum2 <<" " << temp << endl;
		}
	}
	cout << ans << endl;
}