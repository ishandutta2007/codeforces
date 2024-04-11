#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
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

const int N=2e5+99;

int n,m,q,res,ans,a[N],b[N],lazy[N << 2];

struct node{ 
	int sum, max;
	node(){
		sum = 0, max =0 ;
	}
} seg[N << 2];

void shift(int,int,int);

node merge(node u,node v){
	node ans;
	ans.sum = u.sum + v.sum;
	ans.max = max(u.max, v.max);
	return ans;
}
void build(int id=1,int l=1,int r=m+1){
	if(l+1==r){
		res += b[l] * (m - l +1);
		seg[id].sum = seg[id].max = b[l];
		//eror(seg[id].max);
		return ;
	}
	int mid=(l+r)/2;
	build(id*2+0,l,mid);
	build(id*2+1,mid,r);
	seg[id]=merge(seg[id*2+0],seg[id*2+1]);
	//cout << l << " " << r << " : " << seg[id].sum << endl;
}
void add(int L,int R,int val,int id=1, int l=1,int r=m+1){
   if(r<=L || R<=l) return ;
   if(L<=l && r<=R){
      lazy[id]+=val;
      seg[id].max += val;
      seg[id].sum += val * (r-l);
      return ;   
   }
   int mid=(l + r) >> 1;
   shift(id, l, r);
   add(L,R,val,id*2+0,l,mid);
   add(L,R,val,id*2+1,mid,r);
   seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}
int query_sum(int L,int R,int id=1,int l=1,int r=m+1){
   if(r<=L || R<=l) return 0;
   if(L<=l && r<=R){
      return seg[id].sum;
   }
   shift(id, l , r);
   int mid=(l + r) >> 1;
   return query_sum(L,R,id*2+0,l,mid) + query_sum(L,R,id*2+1,mid,r);
}
int query(int val,int id=1,int l=1,int r=m+1){
   shift(id, l, r);
   if(seg[id].max <= val){
   	return r;
	}
	if(l + 1 == r){
		return l;
	}
	int mid=(l + r) >> 1;
	shift(id, l, r);
   if(seg[id * 2 + 0].max > val){
   	return query(val, id * 2 + 0, l, mid);
	}
	return query(val, id * 2 + 1, mid, r);
}

void read(){
	cin >> n >> m >> q;
	f(i,0,n) cin >> a[i];
	f(i,0,m) cin >> b[i];
	f_(i,n-1,1) a[i] -= a[i-1];
	f_(i,m-1,1) b[i] -= b[i-1];
	res += a[0] * (n + m -1);
	res += b[0] * (n + m -1);
	n--,m--;
	build();
}
void shift(int id,int l,int r){
	int mid = (l + r) >> 1;
   seg[2 * id + 0].max += lazy[id];
   seg[2 * id + 0].sum += lazy[id] * (mid-l);
   lazy[2 * id + 0] += lazy[id];
	seg[2 * id + 1].max += lazy[id];
   seg[2 * id + 1].sum += lazy[id] * (r-mid);
   lazy[2 * id + 1] += lazy[id];
   lazy[id]=0;
}
void find_pos(int x){
	int u = query(x);
	ans += query_sum(1, u);
	ans += x * (m - u + 1);
}
void solve(){
	ans = 0;
	f(i,1,n+1){
		ans += a[i] * (n - i + 1);
		find_pos(a[i]);
	}
	cout << ans+res << endl;
	//cout << ans + res << " ---------------- " << ans << " " << res << endl;
}
void Main(){
	//solve();
	//return ;
	while(q--){
		int type, k, d;
		cin >> type >> k >> d;
		if(type == 1){
			if(k == n+1){
				k--;
				res += d * (n + m + 1);
			}
			f(i,n-k+1,n+1){
				a[i] += d;
			}
		}
		else{
			if(k == m+1){
				k--;
				res += d * (n + m + 1);
			}
			res += d * k * (k+1) / 2;
			add(m-k+1, m+1, d);
		}
		solve();
	}
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read();
	Main();
}
/*
2 2 2
1 2
1 2
1 2 10
2 1 10
*/