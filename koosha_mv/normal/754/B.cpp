#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
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
#define int ll

const int N=100,dx[8]={1,1,1,0,-1,-1,-1,0},dy[8]={-1,0,1,1,1,0,-1,-1};

int n=4,t,a[N][N];
string s[N];

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	f(i,1,n+1){
		cin>>s[i];
		s[i]=' '+s[i];
	}
	f(i,1,n+1){
		f(j,1,n+1){
			if(s[i][j]=='o') continue ;
			f(p,0,4){
				int check=1,cnt=s[i][j]=='.';
				int x,y,k;
				k=p;
				x=i+dx[k],y=j+dy[k];
				if(x<1 || 4<x || y<1 || 4<y || s[x][y]=='o'){
					check=0;
					continue ;
				}
				cnt+=s[x][y]=='.';
				k=p+4;
				x=i+dx[k],y=j+dy[k];
				if(x<1 || 4<x || y<1 || 4<y || s[x][y]=='o'){
					check=0;
					continue ;
				}
				cnt+=s[x][y]=='.';
				if(cnt<=1){
					cout<<"YES";
					exit(0);
				}
			}
		}
	}
	cout<<"NO";
}