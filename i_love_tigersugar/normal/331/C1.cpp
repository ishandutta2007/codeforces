#include<cstdio>
#include<queue>
#define MAX   1001001
using namespace std;
int c[MAX];
int l[MAX];
queue<int> q;
struct bignum {
	int nd;
	int d[17];
	bignum(){
		nd=0;
	}
	bignum(int x) {
		if (x==0) {
			nd=1;
			d[0]=0;
		}
		nd=0;
		while (x>0) {
			nd++;
			d[nd-1]=x%10;
			x=x/10;
		}
	}
};
int s;
void init(void) {
	scanf("%d",&s);	
}
void BFS(void) {	
	while (!q.empty()) q.pop();
	bignum tmp=bignum();
	int i,x;
	c[s]=1;
	l[s]=0;
	q.push(s);
	while (!q.empty()) {
		x=q.front();q.pop();
		if (x==0) {
			printf("%d",l[x]);
			return;
		}
		tmp=bignum(x);
		for (i=0;i<tmp.nd;i=i+1)
			if (c[x-tmp.d[i]]==0) {
				c[x-tmp.d[i]]=1;
				l[x-tmp.d[i]]=l[x]+1;
				q.push(x-tmp.d[i]);
			}
	}
}
int main(void) {
	init();
	BFS();
	return 0;
}