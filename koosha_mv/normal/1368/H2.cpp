#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+99,inf=1e6;

int n,m,q,a[N];
string s1,s2,s3,s4;

struct Seg{
	struct node{
		int len,lz=0,cnt[2][2],res[2][2][4];
		node(){
			f(s,0,2) f(t,0,2) f(k,0,4) cnt[s][t]=0,res[s][t][k]=inf;
		}
		void build(char c1,char c2){
			int b1=(c1=='B'),b2=(c2=='B');
			cnt[0][b1]++;
			cnt[1][b2]++;
			f(s,0,2){
				f(t,0,2){
					f(k,0,4){
						if(s!=t){
							res[s][t][k]=inf;
							continue ;
						}
						res[s][t][k]=(s^b1^bit(k,0))+(t^b2^bit(k,1));
					}
				}
			}
		}
		void change(int mask){
			f(s,0,2) f(t,0,2) f(k,0,4) if(k<(k^mask)) swap(res[s][t][k],res[s][t][k^mask]);
			if(bit(mask,0)) swap(cnt[0][0],cnt[0][1]);
			if(bit(mask,1)) swap(cnt[1][0],cnt[1][1]);
			lz^=mask;
		}
		node friend operator + (node A,node B){
			node ans;
			ans.len=A.len;
			f(sa,0,2){
				f(sb,0,2){
					f(ta,0,2){
						f(tb,0,2){
							f(k,0,4){
								minm(ans.res[sa][tb][k],A.res[sa][ta][k]+B.res[sb][tb][k]+(ta!=sb)*A.len);
							}
						}
					}
				}
			}
			f(i,0,2) f(j,0,2) ans.cnt[i][j]=A.cnt[i][j]+B.cnt[i][j];
			return ans;
		}
	} seg[N<<2];
	
	string s[2];
	void read(int p){
		cin>>s[0]>>s[1];
		f(i,0,N<<2) seg[i].len=p;
	}
	void shift(int id){
		seg[id<<1].change(seg[id].lz);
		seg[id<<1|1].change(seg[id].lz);
	}
	void build(int id,int l,int r){
		if(l+1==r){
			seg[id].build(s[0][l],s[1][l]);
			return ;
		}
		int mid=(l+r)>>1;
		build(id<<1,l,mid);
		build(id<<1|1,mid,r);
		seg[id]=seg[id<<1]+seg[id<<1|1];
	}
	void change(int L,int R,int mask,int id,int l,int r){
		if(r<=L || R<=l) return ;
		if(L<=l && r<=R){
			seg[id].change(mask);
			return ;
		}
		int mid=(l+r)>>1;
		shift(id);
		change(L,R,mask,id<<1,l,mid);
		change(L,R,mask,id<<1|1,mid,r);
		seg[id]=seg[id<<1]+seg[id<<1|1];
	}
} seg1,seg2;

void solve(){
	int ans=inf;
	f(s,0,2) f(t,0,2){
		minm(ans,seg1.seg[1].res[s][t][0]+seg2.seg[1].cnt[0][s^1]+seg2.seg[1].cnt[1][t^1]);
		minm(ans,seg2.seg[1].res[s][t][0]+seg1.seg[1].cnt[0][s^1]+seg1.seg[1].cnt[1][t^1]);
	}
	cout<<ans<<endl;
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m>>q;
	seg1.read(m);
	seg2.read(n);
	seg1.build(1,0,n);
	seg2.build(1,0,m);
	solve();
	f(i,0,q){
		char c;
		int l,r;
		cin>>c>>l>>r; l--;
		if(c=='L'){
			seg1.change(l,r,1,1,0,n);
		}
		if(c=='R'){
			seg1.change(l,r,2,1,0,n);
		}
		if(c=='U'){
			seg2.change(l,r,1,1,0,m);
		}
		if(c=='D'){
			seg2.change(l,r,2,1,0,m);
		}
		solve();
	}
}