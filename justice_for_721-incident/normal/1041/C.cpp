#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
#define fi first
#define se second
queue<pair<ll,int> >q;
int cnt=0;
int n;
ll m,d;
pair<ll,int> a[200001];
int ans[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> d;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi;
		a[i].se=i;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n ;i++){
		if(q.empty() || q.front().fi+d>=a[i].fi){
			cnt++;
			ans[a[i].se]=cnt;
			q.push({a[i].fi,cnt});
		}
		else{
			int num=q.front().se;
			q.pop();
			ans[a[i].se]=num;
			q.push({a[i].fi,num});
		}
	}
	cout << q.size() << endl;
	for(int i=1; i<=n ;i++) cout << ans[i] << ' ';
}