#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> v,ans,v2,v1;
int i,j,k,n,m,t,l,r,md,res;
queue<pair<int,int> >q,q2;
#define get(x,y) if(v2[x][y]=='X'){v2[x][y]='.';q2.push({x,y});}
#define get2(x,y) if(v2[x][y]=='.'){v2[x][y]='X';q2.push({x,y});}

bool chk(int x){
	if(!x){
		v1=v;return 1;
	}
	x--;
	
	queue<pair<int,int> >clr;
	swap(q,clr);
	v2=v;
	int i,j,k;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(v[i][j]!='X'){continue;}
			if(
				v[i-1][j-1]!='X'||v[i-1][j]!='X'||v[i-1][j+1]!='X'||
				v[i][j-1]!='X'||v[i][j+1]!='X'||
				v[i+1][j-1]!='X'||v[i+1][j]!='X'||v[i+1][j+1]!='X'
			){
				q.push({i,j});
				v2[i][j]='.';
			}
		}
	}
	for(i=1;i<=x;i++){
		while(!q.empty()){
			auto [x,y]=q.front();q.pop();
			get(x-1,y-1);get(x-1,y);get(x-1,y+1);
			get(x,y-1);get(1,y+1);
			get(x+1,y-1);get(x+1,y);get(x+1,y+1);
		}
		swap(q,q2);
	}
	v1=v2;
	
	//nmsl
	/*for(auto i:v1){
		cout<<i<<endl;
	}*/
	
	queue<pair<int,int> >clr2;
	swap(q,clr2);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(v2[i][j]!='X'){continue;}
			q.push({i,j});
		}
	}
	
	for(i=1;i<=x+1;i++){
		while(!q.empty()){
			auto [x,y]=q.front();q.pop();
			get2(x-1,y-1);get2(x-1,y);get2(x-1,y+1);
			get2(x,y-1);get2(x,y+1);
			get2(x+1,y-1);get2(x+1,y);get2(x+1,y+1);
		}
		swap(q,q2);
	}
	
	//nmsl
	/*for(auto i:v2){
		cout<<i<<endl;
	}*/
	
	for(i=1;i<=n;i++){
		if(v2[i]!=v[i]){return 0;}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	scanf("%d%d",&n,&m);
	string s;
	for(i=0;i<=m+1;i++){s+="?";}
	v.push_back(s);
	for(i=1;i<=n;i++){
		s.clear();
		for(j=1;j<=m;j++){
			char c=getchar();
			if(c=='X'||c=='.'){s+=c;}
			else{j--;}
		}
		s="?"+s+"?";
		v.push_back(s);
	}
	s.clear();
	for(i=0;i<=m+1;i++){s+="?";}
	v.push_back(s);
	l=0;r=n+1;
	while(l<=r){
		md=(l+r)/2;
		if(chk(md)){
			res=max(res,md);l=md+1;ans=v1;
		}
		else{
			r=md-1;
		}
	}
	printf("%d\n",res);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			putchar(ans[i][j]);
		}
		putchar('\n');
	}
}