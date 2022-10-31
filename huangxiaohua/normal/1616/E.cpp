#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
queue<int> q[256];
char s1[200500],s2[200500];
ll res,sb,tmp;
int f[200500];
void add(int x,int y){
	for(;x;x-=(-x&x))f[x]+=y;
}
int get(int x,int y=0){
	for(;x<=n;x+=(-x&x)){y+=f[x];}return y;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s1+1>>s2+1;
		for(i='a';i<='z';i++){
			queue<int> clr;
			swap(clr,q[i]);
		}
		for(i=1;i<=n;i++){
			f[i]=0;
			q[s1[i]].push(i);
		}
		res=1e18;
		tmp=0;
		for(i=1;i<=n;i++){
			for(j='a';j<s2[i];j++){
				if(q[j].empty())continue;
				k=q[j].front();
				res=min(res,tmp+k+get(k)-i);
			}
			//cout<<i<<' '<<res<<endl;
			if(q[s2[i]].empty())break;
			k=q[s2[i]].front();
			q[s2[i]].pop();
			tmp+=k+get(k)-i;
			add(k,1);
		}
		for(i=1;i<=n;i++){
			f[i]=0;
		}
		if(res>1e17){
			res=-1;
		}
		cout<<res<<'\n';
	}
}