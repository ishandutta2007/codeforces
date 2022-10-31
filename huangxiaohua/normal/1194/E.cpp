////
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x1 nmsl1
#define x2 nmsl2
#define y1 nmsl3
#define y2 nmsl4

int i,j,k,n,m,t,x1,y1,x2,y2,a[11050];
vector<pair<int,int> >v1[11050],v2[11050];//v2:pos,end
struct sb{int pos,end;bool operator<(const sb x)const{return end>x.end;}}tmp;
priority_queue<sb> q;
ll res,tmp2;
void add(int x,int y){
	for(;x<=11001;x+=(-x&x)){a[x]+=y;}
}
int get(int x,int y=0){
	for(;x;x-=(-x&x)){y+=a[x];}return y;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1+=5005;x2+=5005;y1+=5005;y2+=5005;
		if(y1>y2){swap(y1,y2);}
		if(x1>x2){swap(x1,x2);}
		if(x1==x2){
			v1[x1].push_back({y1,y2});
		}
		else{
			v2[x1].push_back({y1,x2});
		}
	}
	for(i=1;i<=10100;i++){
		for(auto [l1,r1]:v1[i]){
			memset(a,0,sizeof(a));
			for(j=1;j<=i;j++){
				for(auto [x,y]:v2[j]){
					if(y<=i||x<l1||x>r1){continue;}
					tmp.pos=x;
					tmp.end=y;
					q.push(tmp);
					add(x,1);
				}
			}
			for(j=i+1;j<=10100;j++){
				for(auto [l2,r2]:v1[j]){
					tmp2=get(r2)-get(l2-1);
					res+=(tmp2*tmp2-tmp2)/2;
				}
				while(!q.empty()&&q.top().end<=j){add(q.top().pos,-1);q.pop();}
			}
			
		}
	}
	
	printf("%lld",res);
}