#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1e5+2;
int t,n,m,mark[N*3],x,y,cnt;
vector<int> ans;
int main(){
	cin>>t;
	f(q,0,t){
		Gett(n,m);
		f(i,0,m){
			Gett(x,y);
			if(!mark[x] && !mark[y]){
				mark[x]=mark[y]=1;
				ans.pb(i+1);
			}
		}
		if(ans.size()>=n){
			cout<<"Matching"<<endl;
			f(i,0,n) cout<<ans[i]<<" ";
		}
		else{
			cnt=0;
			cout<<"IndSet"<<endl;
			f(i,1,n*3+1){
				if(!mark[i] && cnt<n){
					cout<<i<<" ";
					cnt++;
				}
			}
			if(cnt<n) return cout<<cnt,0;
		}
		ans.clear();
		fill(mark,mark+n+n+n+2,0);
		cout<<endl;
	}
}