#include <cstdio>
#include <queue>

int q,cnt,now=1;
bool del[500001];
std::priority_queue<std::pair<int,int> >heap;
int main(){
	scanf("%d",&q);
	for(int i=1,opt,x;i<=q;i++){
		
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&x);
			heap.push(std::make_pair(x,-(++cnt)));
		}
		else if(opt==2){
			while(del[now])++now;
			printf("%d ",now);
//			putchar('*');
//			putchar('\n');
			del[now]=1;
		}
		else{
			while(!heap.empty()&&del[-heap.top().second])heap.pop();
			printf("%d ",-heap.top().second);
//			putchar('*');
//			putchar('\n');
			del[-heap.top().second]=1;
		}
	}
	
}