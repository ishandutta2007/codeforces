#include <bits/stdc++.h>
using namespace std;
typedef long long ll;//
#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,it,res,mp[22][400500],cl,cr,l[66],r[66];
int f[3005000],cnt[3005000];
string sb;
int main(){
	cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>sb;
		cl=cr=0;
		for(auto j:sb){
			if(j=='(')cl++;
			else{
				if(cl)cl--,mp[i][cr]+=(!cl);
				else cr++;
			}
		}
		l[i]=cl;r[i]=cr;
	}
	memset(cnt,-1,sizeof(cnt));cnt[0]=0;
	for(i=0;i<b(n+1);i++){
		res=max(res,f[i]);
		if(cnt[i]==-1)continue;
		for(j=1;j<=n;j++){
			if(b(j)&i)continue;
			k=b(j)+i;
			if(!cnt[i]){
				if(r[j])res=max(res,f[i]+mp[j][0]);
				else cnt[k]=cnt[i]+l[j],f[k]=max(f[k],f[i]+mp[j][0]);
				continue;
			}
			if(r[j]>cnt[i])res=max(res,f[i]+1+mp[j][cnt[i]]);
			else{
				cnt[k]=cnt[i]+l[j]-r[j];
				if(r[j]==cnt[i])f[k]=max(f[k],f[i]+1+mp[j][cnt[i]]);
				else f[k]=max(f[k],f[i]);
			}
		}
	}
	cout<<res;
}