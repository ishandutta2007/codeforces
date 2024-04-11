#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll t,mark[100009],ans,deg[100009],n,x,y,z;
vector<int> g[100009];
ll check(int x){
	while(x>0){
		if(x%10!=4 && x%10!=7)
			return 0;
		x/=10;
	}
	return 1;
}
int moalefe(int x){
	t++;mark[x]=1;
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==0){
			moalefe(g[x][i]);
		}
	}
	return 0;
}
int main(){
	cin>>n;
	f(i,0,n-1){
		cin>>x>>y>>z;
		if(check(z)==0){
			g[x].push_back(y);deg[y]++;
			g[y].push_back(x);deg[x]++;
		}
	}
	f(i,1,n+1){
		if(mark[i]==0 && deg[i]>=1){
			t=0;
			moalefe(i);
			ans+=((t*(t-1))/2)*4*(n-t);
			if(t>2){
				ans+=(t*(t-1)*(t-2));
			}
		}
	}
	cout<<(n*(n-1)*(n-2))-ans;
}