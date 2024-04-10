#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int n; ll o_x,o_y,x[2100],y[2100],t[2100];
map<pii,bool> mp;
inline int gcd(int x,int y) {
    return y?gcd(y,x%y):x;
}
bool check(int a,int b){
	ll mid_x=(x[a]+x[b]),mid_y=(y[a]+y[b]);
	ll g=gcd(mid_x,mid_y); mid_x/=g; mid_y/=g;
	if (mp[pii(mid_x,mid_y)]) return false;
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (x[i]||y[i]) cnt++,t[cnt]=mid_x*y[i]-mid_y*x[i];
	sort(t+1,t+cnt+1);
	for (int i=1;i<=cnt;i++)
		if (t[i]+t[cnt-i+1]) return false;
	mp[pii(mid_x,mid_y)]=true;
	return true;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		o_x+=x[i]; o_y+=y[i];
		x[i]*=n; y[i]*=n;
	}
	int a=0;
	for (int i=1;i<=n;i++) x[i]-=o_x,y[i]-=o_y;
	bool flag;
	for (int i=1;i<=n;i++){
		flag=false;
		for (int j=1;j<=n;j++)
			if (x[i]+x[j]==0&&y[i]+y[j]==0){
				flag=true;
				break;
			}
		if (!flag&&!a) a=i;
	}
	if (!a){ puts("-1"); return 0;}
	int ans=0;
	for (int i=1;i<=n;i++)
		if (check(a,i)) ans++;
	printf("%d\n",ans);
	return 0;
}
/*
10
-8 11
1 10
2 10
2 11
0 9
3 12
-7 16
11 4
4 8
12 9
*/