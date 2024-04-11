#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N = 5e5+99, sq = 740, inf=1e9+9;
 
int n,q;
int a[N],lazy[sq];
map<int,int> mark[sq];
 
void change(int x, int y){
	mark[x/sq][a[x]]--;
	if(mark[x / sq][a[x]] == 0) mark[x / sq].erase(a[x]);
	a[x] = min(y, inf);
	mark[x / sq][a[x]]++;
}
void add(int l,int r,int x){
	while(l % sq != 0 && l <= r){
		change(l, a[l] + x);
		l++;
	}
	if(l>r) return ;
	while((r+1) % sq != 0){
		change(r, a[r] + x);
		r--;
	}
	while(l<r){
		lazy[l / sq] += x;
		minm(lazy[l / sq], inf);
		l += sq;
	}
}
void get(int x){
	int l=-1,r=-1;
	f(i, 0, sq){
		if(x-lazy[i]>=0 && mark[i].count(x - lazy[i])){
			f(j, i * sq, i * sq + sq){
				if(a[j] + lazy[i] == x){
					l = j;
					break;
				}
			}
			break;
		}
	}
	f_(i,sq-1,0){
		if(x-lazy[i]>=0 && mark[i].count(x - lazy[i])){
			f_(j, i * sq + sq-1, i*sq){
				if(a[j] + lazy[i] == x){
					r = j;
					break;
				}
			}
			break;
		}
	}
	if(l == -1) cout << -1 << '\n';
	else cout << r - l << '\n';
}
 
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	f(i, 0, n){
		cin >> a[i];
		mark[i / sq][a[i]]++;
	}
	f(i, 0, q){
		int type, l, r, x;
		cin >> type;
		if(type == 1){
			cin >> l >> r >> x;
			l--, r--;
			add(l, r, x);
		}
		else{
			cin >> x;
			get(x);
		}
	}
}