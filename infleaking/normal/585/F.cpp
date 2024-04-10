#include<bits/stdc++.h>
using namespace std;
const int M=50100,N=55,mo=1e9+7;
int tr[M][10],fail[M],n,d,t=1,tag[M];
char s[M],a[M],b[M];
int f[N][M][2];
void move(int &a,long long b){a=(a+b)%mo;}
vector<int> h;
int dp(char *a){
	f[0][1][1]=1;
	for (int i=1;i<=d;i++){
		for (int j=1;j<=t;j++){
			if (!f[i-1][j][0]&&!f[i-1][j][1])continue;
			for (int x=0;x<10;x++){
				int j1=j;
				while (!tr[j1][x]&&j1)j1=fail[j1];
				j1=tag[j]?j:(j1?tr[j1][x]:1);
				if (x<a[i]-'0')
					move(f[i][j1][0],f[i-1][j][0]+f[i-1][j][1]);
				if (x==a[i]-'0')
					move(f[i][j1][0],f[i-1][j][0]),
					move(f[i][j1][1],f[i-1][j][1]);
				if (x>a[i]-'0')
					move(f[i][j1][0],f[i-1][j][0]);
			}
		}
	}
	int ans=0;
	for (int i=1;i<=t;i++)
		if (tag[i])move(ans,f[d][i][0]+f[d][i][1]);
	memset(f,0,sizeof f);
	return ans;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%s",a+1);
	scanf("%s",b+1);
	d=strlen(a+1);
	for (int i=d;i>=1;i--){
		if (a[i]=='0')a[i]='9';
		else {
			a[i]--;
			break;
		}
	}
	for (int i=1;i<=n-d/2+1;i++){
		int now=1;
		for (int j=i;j<i+d/2;j++){
			if (!tr[now][s[j]-'0'])tr[now][s[j]-'0']=++t;
			now=tr[now][s[j]-'0'];
		}
		tag[now]=1;
	}
	for (int i=0;i<10;i++){
		if (tr[1][i]){
			fail[tr[1][i]]=1;
			h.push_back(tr[1][i]);
		}
	}
	for (int i=0;i<h.size();i++){
		int x=h[i];
		for (int d=0;d<10;d++){
			int z=tr[x][d],k=fail[x];
			if (!z)continue;
			while (k&&!tr[k][d])k=fail[k];
			fail[z]=k?tr[k][d]:1;
			h.push_back(z);
		}
	}
	cout<<(dp(b)-dp(a)+mo)%mo<<endl;
}