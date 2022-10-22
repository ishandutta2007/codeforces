#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99,m=22;

int n,t,x,s,ans,a[N],l[m];
int v[2][m][N];

void upd(int s,int x,int k){
	if(v[s][x][k]<l[x]) v[s][x][k]=N;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	f(s,0,2)
		f(i,0,m)
			f(j,0,N)
				v[s][i][j]=(j==0 && s==0 ? 0 : N);
	cin>>n;
	f(i,1,n+1){
		int u=0,s=i&1;
		cin>>a[i];
		x^=a[i];
		f(j,0,m)
			if((a[i]&(1<<j))==0)
				l[j]=i;
		f_(j,m-1,0){
			upd(s,j,u);
			maxm(ans,i-v[s][j][u]);
			minm(v[s][j][u],i);
			u=u*2;
			if(x&(1<<j)) u++;
		}
	}
	cout<<ans;
}