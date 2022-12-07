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

const int N = 100005;
int n,a[N],f[N][301];
int p,k,i,j,q;
int main() {
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	for (i=n;i>=1;i--){
		for (j=1;j<=300;j++)
			if (i+a[i]+j>n) f[i][j]=1;
			else f[i][j]=f[i+a[i]+j][j]+1;
	}

	scanf("%d",&q);
	for (i=1;i<=q;i++){
		scanf("%d%d",&p,&k);
		if (k<=300)
			printf("%d\n",f[p][k]);
		else{
			int cnt=0;
			while (p<=n){
				cnt++;
				p=p+a[p]+k;
			}
			printf("%d\n",cnt);
		}
	}
}