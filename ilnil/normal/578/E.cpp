#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
using namespace std;
const int N=1e5+5;
int n,a[N],b[N],cnt2,cnt,wz;
char c[N];
set<int>s[2];
bool bz[N];
void work(int &cnt,int *a){
	wz=0;
	for(int o=0,las=0;s[0].size()||s[1].size();o^=1){
		if(*s[o].rbegin()<las){
			++cnt;
			a[++wz]=*s[o].begin();
		}else{
			a[wz+1]=*s[o].upper_bound(las);++wz;
			if(s[!o].size()&&*s[o].begin()<*s[!o].begin()&&a[wz]>*s[!o].rbegin())
				a[wz]=*s[o].begin();
			cnt+=a[wz-1]>a[wz];
		}
		s[o].erase(a[wz]);las=a[wz];
	}
	if(wz>3&&a[wz-2]>a[wz-1]&&a[wz-1]>a[wz])--cnt,swap(a[wz-2],a[wz]);
}
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	fo(i,1,n)s[c[i]=='R'].insert(i);
	if(s[0].size()<s[1].size())swap(s[0],s[1]);
	work(cnt,a);
	if(~n&1){
		fo(i,1,n)s[c[i]=='R'].insert(i);
		swap(s[0],s[1]);
		work(cnt2,b);
		if(cnt2<cnt)swap(a,b),swap(cnt,cnt2);
	}
	cout<<cnt<<endl;
	fo(i,1,n)printf("%d ",a[i]);
}