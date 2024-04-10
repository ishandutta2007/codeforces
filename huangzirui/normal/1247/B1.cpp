#include <bits/stdc++.h>
#define ll long long
using namespace std;
int i,j,k,n,m;
void read(int &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
void read(ll &x){
	char c;x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;
}
int a[200010],L,R;
bool B[1000010];
int s[1000010];
int main() {
	int t;
	read(t);
	while(t--){
		read(n);read(m);read(k);
		for(i=1;i<=n;i++)
			read(a[i]);
		memset(B,0,sizeof(B));
		memset(s,0,sizeof(s));
		int num=0,ans=1e9;
		for(i=1;i<k;i++){
			s[a[i]]++;
			if(s[a[i]]==1)num++;
		}
		for(L=1;L<=n-k+1;L++){
			R=L+k-1;
			s[a[R]]++;
			if(s[a[R]]==1)num++;
			ans=min(ans,num);
			s[a[L]]--;
			if(s[a[L]]==0)num--;
		}cout<<ans<<endl;
	}
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}