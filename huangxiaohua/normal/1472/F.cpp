#include<bits/stdc++.h>
using namespace std;


int i,j,k,n,m,t,x,y,ll,rr,tmp,tmp2;
bool yes;

priority_queue<int,vector<int>,greater<int> >l,r;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		x=y=0;
		ll=rr=tmp=0;
		yes=1;
		for(i=1;i<=m;i++){
			scanf("%d",&k);
			if(k==2){
				scanf("%d",&j);
				l.push(j);
			}
			else{
				scanf("%d",&j);
				r.push(j);
			}
			//printf("%d\n",j);
		}
		l.push(n+1);
		r.push(n+1);
		while(!l.empty()||!r.empty()){
			if(l.top()==r.top()){
				//printf("%d %d\n",x%2,y%2);
				if(x%2!=y%2){yes=0;}
				l.pop();r.pop();
				continue;
			}
			
			if(l.top()<r.top()){
				
				
				tmp=(l.top()-x-1)%2;
				tmp2=(l.top()-y-1)%2;
				
				//printf("l%d %d %d %d %d\n",l.top(),tmp,tmp2,x,y);
				if(tmp){
					if(tmp!=tmp2){yes=0;}
					y=l.top()-1;
				}
				x=l.top();l.pop();
			}
			else{
				
				tmp=(r.top()-y-1)%2;
				tmp2=(r.top()-x-1)%2;
				
				//printf("r%d %d %d %d %d\n",r.top(),tmp,tmp2,x,y);
				if(tmp){
					if(tmp!=tmp2){yes=0;}
					x=r.top()-1;
				}
				y=r.top();r.pop();
			}
		}
		if(yes){puts("YES");
		}else{puts("NO");
		}
	}
}