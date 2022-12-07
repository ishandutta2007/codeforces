#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

int N,S,a[5],ans,x;

int main() {
	scanf("%d",&N);
	for (int i=1; i<=N; i++) scanf("%d",&x),a[x]++,S+=x;
	if (S<3||S==5) {puts("-1"); return 0;}
	ans=x=a[1]<a[2]?a[1]:a[2],a[1]-=x,a[2]-=x,a[3]+=x;
	if (a[1]) a[3]+=x=a[1]/3,a[1]%=3,ans+=2*x+(!a[1]?0:a[1]==1&&a[3]?1:2);
	if (a[2]) a[3]+=2*(x=a[2]/3),a[2]%=3,ans+=2*x+(!a[2]?0:a[2]==1&&a[4]?1:2);
	printf("%d\n",ans);
	return 0;
}