#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int T,n,cnt[110000],p[110000],pos[110000];
int lst[110000],nxt[110000];
multiset<int> s;
bool solve(){
	for (int i=1;i<=n;i++){
		int now=pos[i];
		if (cnt[now]!=*s.rbegin()) return false;
		s.erase(s.find(cnt[now]));
		if (nxt[now]!=n+1){
			s.erase(s.find(cnt[nxt[now]]));
			cnt[nxt[now]]+=cnt[now];
			s.insert(cnt[nxt[now]]);
		}
		nxt[lst[now]]=nxt[now]; lst[nxt[now]]=lst[now];
		cnt[now]=0;
	}
	return true;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d",&p[i]);
			pos[p[i]]=i;
		}
		nxt[0]=1; lst[1]=0;
		nxt[n]=n+1; lst[n+1]=n;
		for (int i=2;i<=n;i++){
			lst[i]=i-1; nxt[i-1]=i;
		}
		s.clear();
		for (int i=1;i<=n;i++){
			cnt[i]=1;
			s.insert(cnt[i]);
		}
		if (solve()) puts("Yes");
		else puts("No");
	}
	return 0;
}