/*#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
using pi = pair<int, int>;
const int MAXN = 100005;
const int mod = 1e9 + 7;

int n, m, a[MAXN], b[MAXN];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	for(int i=0; i<m; i++) scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+m);
	if(a[n-1] > b[0]){
		puts("-1");
		return 0;
	}
	lint ret = 1ll * m *accumulate(a, a + n, 0ll);
	for(int i=0; i<n; i++){

	}
}*/
#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;

struct pnt{
	int x, y, idx;
}a[5005];

lint ccw(pnt a, pnt b, pnt c){
	int dx1 = b.x - a.x;
	int dy1 = b.y - a.y;
	int dx2 = c.x - a.x;
	int dy2 = c.y - a.y;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}

int n;
bool vis[5005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i].x >> a[i].y;
		a[i].idx = i+1;
	}
	swap(a[0], *min_element(a, a+n, [&](const pnt &a, const pnt &b){
				return pi(a.x, a.y) < pi(b.x, b.y);
				}));
	sort(a+1, a+n, [&](const pnt &p, const pnt &q){
			return ccw(a[0], p, q)  > 0;
			});
	string x; cin >> x;
	if(x[0] == 'R') swap(a[1], a[n-1]);
	vis[0] = vis[1] = 1;
	printf("%d %d ",a[0].idx, a[1].idx);
	int prv = 1;
	for(int i=2;i<n - 1; i++){
		int cur = -1;
		if(x[i - 1] == 'L'){
			for(int j=0; j<n; j++){
				if(!vis[j]){
					if(cur == -1) cur = j;
					else if(ccw(a[prv], a[cur], a[j]) < 0) cur = j;
				}
			}
		}
		else{
			for(int j=0; j<n; j++){
				if(!vis[j]){
					if(cur == -1) cur = j;
					else if(ccw(a[prv], a[cur], a[j]) > 0) cur = j;
				}
			}

		}
		vis[cur] = 1;
		printf("%d ", a[cur].idx);
		prv = cur;
	}
	for(int i=0; i<n; i++) if(!vis[i]) printf("%d", a[i].idx);
}