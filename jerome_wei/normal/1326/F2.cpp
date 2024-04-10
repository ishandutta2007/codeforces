#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char s[20][20];
ll f[20][1<<18];
ll h[20][1<<18];

inline void fwt(ll *f,int n,int type){// type = 1 : or, type = 0 : and
	for(int step=1;step<n;step<<=1){
		for(int i=0;i<n;i+=step<<1){
			for(int j=0;j<step;j++){
				if(type)f[i+j+step]=f[i+j+step]+f[i+j];
				else f[i+j]-=f[i+j+step];
			}
		}
	}
}
ll dp[1<<18];

inline void find(int x,int curs,int pre,int id,ll curf){
	// cout << x << " | " << curs << " " << pre << endl;
	if(x==n){
		dp[curs]+=(((n-__builtin_popcount(id))&1)?-1ll:1ll)*curf;
		return ;
	}
	if(x+pre>n)return ;
	if(x+pre+1<=n){
		find(x,curs,pre+1,id,curf);
	}
	curs<<=1; curs<<=pre-1;
	curs|=(1<<(pre-1))-1;//pre-11
	curf*=h[pre][id];
	find(x+pre,curs,pre,id,curf);
}
inline void transfer(int s){
	vector<int> l;
	for(int i=0,j;i<=n;i=j+1){
		j=i;
		while(j+1<=n&&(1&(s>>j)))++j;
		l.push_back(j-i+1);
	}
	sort(l.begin(),l.end());
	int t=0;
	for(size_t i=0;i<l.size();i++){
		t<<=1,t<<=l[i]-1;
		t|=(1<<(l[i]-1))-1;
	}
	dp[s] = dp[t];
	// cout << s << "from" << t << endl;
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)scanf("%s",s[i]);

	f[0][0]=1;
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<n;j++)if(i&(1<<j)){
			for(int k=0;k<n;k++)if((1<<k)&(i-(1<<j))){
				if(s[k][j]=='1')f[j][i] += f[k][i-(1<<j)];
			}
			if(i==(1<<j)){
				f[j][i]=1;
			}
			h[__builtin_popcount(i)][i] += f[j][i];
		}
	}
	for(int i=1;i<=n;i++){
		// for(int j=0;j<1<<n;j++)cout << h[i][j] << " ";puts("");
		fwt(h[i],1<<n,1);
	}
	for(int i=0;i<1<<n;i++){
		find(0,0,1,i,1);
		// for(int i=0;i<1<<(n-1);i++){
		// 	cout << dp[i] << " ";
		// }puts("");
	}
	for(int i=0;i<1<<(n-1);i++){
		transfer(i);
		// cout << dp[i] << "?" << endl;
	}
	fwt(dp, 1<<(n-1), 0);
	for(int i=0;i<(1<<(n-1));i++){
		printf("%lld ",dp[i]);
	}puts("");
	return 0;
}