#include <bits/stdc++.h>
using namespace std;

stack<int> low[2],high[2]; 

int main(){
	int t,n,i,x,y,ans0,ans1,f;
	char ch;
	cin >> t;
	while(t--){
		f=0;
		scanf("%d",&n);
		while(!low[0].empty())
			low[0].pop();
		while(!low[1].empty())
			low[1].pop();
		while(!high[0].empty())
			high[0].pop();
		while(!high[1].empty())
			high[1].pop();
		
		for(i=1;i+1<=n;i+=2){
			printf("? %d %d\n",i,i+1);
			f++;
			fflush(stdout);
			scanf(" %c",&ch);
			if(ch=='>'){
				high[0].push(i);
				low[0].push(i+1);
			}
			else{
				low[0].push(i);
				high[0].push(i+1);
			}
		}
		if(n&1){
			low[0].push(n);
			high[0].push(n);
		}

		int cur=0,nxt=1;
		while(1){
			if(low[cur].empty()){
				swap(cur,nxt);
			}
			x=low[cur].top();
			low[cur].pop();
			if(low[cur].empty()){
				if(low[nxt].empty()){
					ans0=x;
					break;
				}
				else{
					low[nxt].push(x);
					continue;
				}
			}
			y=low[cur].top();
			low[cur].pop();
			printf("? %d %d\n",x,y);
			fflush(stdout);
			f++;
			scanf(" %c",&ch);
			if(ch=='<')
				low[nxt].push(x);
			else
				low[nxt].push(y);
		}

		cur=0,nxt=1;
		while(1){
			if(high[cur].empty()){
				swap(cur,nxt);
			}
			x=high[cur].top();
			high[cur].pop();
			if(high[cur].empty()){
				if(high[nxt].empty()){
					ans1=x;
					break;
				}
				else{
					high[nxt].push(x);
					continue;
				}
			}
			y=high[cur].top();
			high[cur].pop();
			printf("? %d %d\n",x,y);
			fflush(stdout);
			f++;
			scanf(" %c",&ch);
			if(ch=='>')
				high[nxt].push(x);
			else
				high[nxt].push(y);
		}
		assert(f<=(3*n+1)/2-2);
		printf("! %d %d\n",ans0,ans1);
		fflush(stdout);
	}
}