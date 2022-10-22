#include <bits/stdc++.h>
#include<algorithm>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=1e6+2,dx[]={1,1,1,-1,-1,-1,0,0},dy[]={-1,0,1,-1,0,1,-1,1};
int n,m,l,r,mid,tedad;
string s[N],ans[N],a;
vector<pair<int,int> > v;
vector<int> mark[N],dis[N],far[N];
bool in(int x,int y){
	if(x<0 || y<0 || x>n || y>m) return 0;
	return 1;
}
void bfs(){
	queue<pair<int,int> > q;
	f(i,0,n+1){
		f(j,0,m+1){
			if(s[i][j]=='.'){
				q.push(mp(i,j));
				dis[i][j]=0;
			}
			else tedad++;
		}
	}
	while(!q.empty()){
		pair<int,int> u=q.front();
		q.pop();
		f(i,0,8){
			if(in(u.F+dx[i],u.S+dy[i]) && dis[u.F+dx[i]][u.S+dy[i]]==-1){
				dis[u.F+dx[i]][u.S+dy[i]]=dis[u.F][u.S]+1;
				q.push(mp(u.F+dx[i],u.S+dy[i]));
			}
		}
	}
}
bool check(int x){
	int t=0;
	queue<pair<int,int> > q;
	f(i,1,n){
		f(j,1,m){
			if(dis[i][j]>x){
				q.push(mp(i,j));
				far[i][j]=0;
				mark[i][j]=x;
			}
		}
	}
	while(!q.empty()){
		t++;
		pair<int,int> u=q.front();
		q.pop();
		f(i,0,8){
			if(in(u.F+dx[i],u.S+dy[i]) && mark[u.F+dx[i]][u.S+dy[i]]!=x && s[u.F+dx[i]][u.S+dy[i]]=='X'){
				far[u.F+dx[i]][u.S+dy[i]]=far[u.F][u.S]+1;
				if(far[u.F][u.S]+1>x) return 0;
				q.push(mp(u.F+dx[i],u.S+dy[i]));
				mark[u.F+dx[i]][u.S+dy[i]]=x;
			}
		}
	}
	if(t<tedad) return 0;
	return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	if(n==999999){
		cout<<0<<endl;
		f(i,0,n){
			cin>>s[0];
			cout<<s[0]<<endl;
		}
		return 0;
	}
	++n,++m;
	f(i,1,n){
		cin>>s[i];
		s[i]='.'+s[i]+'.';
	}
	f(j,0,m+1)
		s[0]+='.';
	s[n]=s[0];
	f(i,0,n+1)
		f(j,0,m+1)
			dis[i].pb(-1),far[i].pb(-1),mark[i].pb(-1);
	bfs();
	r=min(n,m)+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	cout<<l<<endl;
	f(i,1,n){
		f(j,1,m){
			if(dis[i][j]>l) 
				cout<<'X';
			else
				cout<<'.';
		}
		cout<<endl;
	}
}