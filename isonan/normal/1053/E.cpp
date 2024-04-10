#include <cstdio>
#include <vector>
#include <cstdlib>

int cnt[500001],n,a[1000001],stk[1000001],top,sum[1000001],q[1000001],h,t;
std::vector<int>clear;
int have[1000001];
void solve(int l,int r){
	int cnt=0;
	if((r-l+1)%2==0){
		puts("no");
		exit(0);
	}
	for(int i=l;i<=r;i++)
		if(stk[i]>0){
			++cnt;
			if(::cnt[stk[i]]>1){
				puts("no");
				exit(0);
			}
			--::cnt[stk[i]];
			have[stk[i]]=0;
		}
//	printf("solve %d %d %d\n",l,r,stk[l]);
	if((cnt<<1)-1>(r-l+1)){
		puts("no");
		exit(0);
	}
	h=t=0;
	auto maintain=[&](){
		for(;;){
			bool did=0;
			if(t-h<3)return;
			if(q[h+1]>0&&q[h+2]>0&&q[h+3]<0){
				a[-q[h+3]]=q[h+1];
				q[h+3]=q[h+1];
				h+=2;
				did=1;
			}
			if(q[h+1]<0&&q[h+2]>0&&q[h+3]>0){
				a[-q[h+1]]=q[h+3];
				h+=2;
				did=1;
			}
			if(q[t]>0&&q[t-1]>0&&q[t-2]<0){
				a[-q[t-2]]=q[t];
				q[t-2]=q[t];
				t-=2;
				did=1;
			}
			if(q[t]<0&&q[t-1]>0&&q[t-2]>0){
				a[-q[t]]=q[t-2];
				t-=2;
				did=1;
			}
			if(!did)return;
		}
	};
	q[++t]=stk[l-1];
	for(int i=l;i<=r;i++){
		q[++t]=stk[i];
		maintain();
//		for(int j=h+1;j<=t;j++)printf("%d ",q[j]);putchar('\n');
	}
	q[++t]=stk[l-1];
	maintain();
//		for(int j=h+1;j<=t;j++)printf("%d ",q[j]);putchar('\n');
//	return;
	for(;;){
		--t,++h;
		if(h>=t)break;
		if(q[h+1]>0||q[t]>0)break;
		a[-q[h+1]]=a[-q[t]]=clear.back();
		q[h+1]=q[t]=clear.back();
		clear.pop_back();
		maintain();
	}
	--::cnt[stk[l-1]];
}
int main(){
	scanf("%d",&n);
	if(n==1){
		printf("yes\n1\n");
		return 0;
	}
	for(int i=1;i<(n<<1);i++)scanf("%d",a+i),++cnt[a[i]];
	for(int i=1;i<=n;i++)if(!cnt[i])clear.push_back(i);
	for(int i=1;i<(n<<1);i++){
		if(!a[i])stk[++top]=-i;
		else{
//			printf("%d %d\n",a[i],have[a[i]]);
			if(have[a[i]])
				solve(have[a[i]]+1,top),top=have[a[i]];
			else{
//	for(int i=1;i<=top;i++)printf("%d ",stk[i]);putchar('\n');
				stk[have[a[i]]=++top]=a[i];
			}
		}
	}
//	printf("%d\n",top);
//	for(int i=1;i<=top;i++)printf("%d ",stk[i]);putchar('\n');
	if(top>1){
		if(stk[1]>0&&stk[top]>0){
			puts("no");
			return 0;
		}
		if(stk[1]<0&&stk[top]<0){
			a[-stk[1]]=clear.back();
			stk[1]=clear.back();
			clear.pop_back();
		}
		if(stk[1]>0&&stk[top]<0)a[-stk[top]]=stk[1],stk[top]=stk[1];
		else if(stk[top]>0&&stk[1]<0)a[-stk[1]]=stk[top],stk[1]=stk[top];
//		printf("*%d\n",a[1]);
		solve(2,top-1);
	}
	puts("yes");
	for(int i=1;i<(n<<1);i++)printf("%d ",a[i]);
}