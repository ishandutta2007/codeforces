#include<bits/stdc++.h>
#define forn(i,a,b)for(int i=(a),_b=(b);i<=_b;i++)
#define fore(i,b,a)for(int i=(b),_a=(a);i>=_a;i--)
#define rep(i,n)for(int i=0,_n=n;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define m_p make_pair
#define pb push_back
#define fi first
#define se second
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();i++)
using namespace std;
const int N=1005;
int n;
bitset<N>f[N],edg[N];
bool g[N][N];
bool leaf[N];
int main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	rep(i,n){
		int x;cin>>x;
		rep(j,x){
			int a;cin>>a;a--;
			f[i][a]=1;
		}
	}
	if(n==2){
		cout<<"1 2\n";
		return 0;
	}
	memset(leaf,1,sizeof(leaf));
	rep(i,n){
		rep(j,i){
			bitset<N>t=f[i]&f[j];
			if(t.count()==2){
				int x=-1,y=-1;
				rep(k,n){
					if(t[k]&&x==-1)x=k;
					else if(t[k])y=k;
				}
				g[x][y]=g[y][x]=1;
				edg[x][y]=1;edg[y][x]=1;
				leaf[x]=leaf[y]=0;
			}
		}
	}
	int tot=0;
	rep(i,n){
		if(!leaf[i])tot++;
	}
	if(tot<=2){
		if(tot==0){
			rep(i,n-1){
				cout<<"1 "<<i+2<<"\n";
			}
		}
		else{
			bitset<N>all;
			rep(i,n)all[i]=1;
			rep(i,n)all&=f[i];
			int x=-1,y=-1;
			rep(i,n){
				if(all[i]){
					if(x==-1)x=i;
					else y=i;					
				}
			} 
			rep(i,n)all[i]=1;
			bitset<N>tt;
			rep(i,n)if(f[i]!=all)tt=f[i];
			cout<<x+1<<" "<<y+1<<"\n";
			rep(i,n){
				if(i==x||i==y)continue;
				if(tt[i])cout<<x+1<<" "<<i+1<<"\n";
				else cout<<y+1<<" "<<i+1<<"\n";
			}
		}
		return 0; 
	}
	bitset<N>r;
	rep(i,n)if(leaf[i])r[i]=0;else r[i]=1;
	rep(i,n){
		if(!leaf[i])edg[i][i]=1;
	}
	rep(i,n){
		if(leaf[i]){
			int p=-1,cnt=0;
			rep(j,n){
				if(f[j][i]){
					int x=f[j].count();
					if(p==-1||x<cnt){
						cnt=x;p=j;
					}
				}
			}
			bitset<N>t=f[p];
			t&=r;
			rep(j,n){
				if(!leaf[j]){
					if(t==edg[j]){
						g[i][j]=g[j][i]=1;
						break;
					} 
				}
			}
		}
	}
	rep(i,n){
		rep(j,i){
			if(g[i][j])cout<<i+1<<" "<<j+1<<"\n";
		}
	}
	return 0;
}