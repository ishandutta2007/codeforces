#include<cstdio>
#include<algorithm>
using namespace std;
int n,cnt,anss[1100000],s[1100000],v[1100000],a[1100000];
void ins(int x){
    int y=x;
    for (int i=20;i>=0;--i)
        if (x&(1<<i)){
            if (v[i]) x^=v[i];
            else {
				v[i]=x; a[i]=y;
				cnt++; return;
			}
        }
}
void dfs(int now){
    if (now==-1) return;
    dfs(now-1); anss[++cnt]=a[now]; dfs(now-1);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&s[i]);
	sort(s+1,s+n+1);
	int i=1,ans=0;
	for (int j=1;j<=20;++j){
        while (i<=n&&s[i]<(1<<j)) ins(s[i++]);
        if (cnt==j) ans=j;
	}
    printf("%d\n",ans);
	cnt=0; dfs(ans);
    for (int i=0;i<(1<<ans);++i){
        if (i) anss[i]^=anss[i-1];
        printf("%d ",anss[i]);
    }
	return 0;
}