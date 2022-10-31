#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int LOG = 31;
struct tnode{
	tnode* to[2];
	int mx[4];
	tnode(){
		to[0] = to[1] = nullptr;
		mx[0] = mx[1] = mx[2] = mx[3] = 0;
	}
	tnode* go(int col){
		if (to[col]==nullptr){
			to[col] = new tnode();
		}
		return to[col];
	}
};
void del(tnode *t){
	for(int c = 0;c<2;c+=1){
		if (t->to[c]!=nullptr){
			del(t->to[c]);
		}
	}
	delete t;
}
void solve() {
	int n;
	cin>>n;
	int res = 0;
	tnode* root = new tnode();
	for(int i = 0;i<n;i+=1){
		int val;
		cin>>val;
		int pref = 0;
		int ans = 0;
		tnode* cur = root;
		for(int lg = LOG-1;lg>=0;lg-=1){
			bool cbit = (i>>lg)%2;
			bool obit = (val>>lg)%2;
			// check cbit^a[oth]&(1<<bit) == 0 and obit^oth&(1<<bit)==1
			ans = max(ans,cur->mx[(1-obit)+2*cbit]);
			// check cbit^a[oth]&(1<<bit) == obit^a[cur]&(1<<bit)
			// means a[oth]^obit == cbit^a[cur]
			if (cur->to[cbit^obit]==nullptr){
				break;
			}
			cur = cur->go(cbit^obit);
		}
//		if (i==1)
//			exit(0);
		ans += 1;
		pref = 0;
		cur = root;
		for(int lg = LOG-1;lg>=0;lg-=1){
			int cr = (i>>lg)%2+2*((val>>lg)%2);
			cur->mx[cr] = max(cur->mx[cr],ans);
			int nxt = ((i^val)>>lg)%2;
			if (lg!=0){
				cur = cur->go(nxt);
			}
		}
		res = max(res,ans);
	}
	cout<<res<<endl;
	del(root);
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}