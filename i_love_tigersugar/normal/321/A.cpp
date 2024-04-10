#include<cstdio>
#include<vector>
#include<cstring>
#define x   first
#define y   second
using namespace std;
typedef pair<int,int> ii;
int n,a,b;
char s[111];
ii p;
vector<ii> v;
void init(void) {
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%s",s);
	n=strlen(s);
}
void move(void) {
	int i;
	p=ii(0,0);
	v.clear();
	v.push_back(p);
	for (i=0;i<n;i=i+1) {
		if (s[i]=='U') p.y++;
		if (s[i]=='D') p.y--;
		if (s[i]=='L') p.x--;
		if (s[i]=='R') p.x++;
		v.push_back(p);
	}		
	if (p.x==0 && p.y==0) {
		for (i=0;i<v.size()-1;i=i+1)
			if (a==v[i].x && b==v[i].y)	{
				printf("Yes");
				return;
			}
		printf("No");
		return;
	}
	if (p.x==0 && p.y!=0) {
		for (i=0;i<v.size()-1;i=i+1)
			if (a==v[i].x && (b-v[i].y)%p.y==0 && (b-v[i].y)/p.y>=0) {
				printf("Yes");
				return;
			}
		printf("No");
		return;
	}
	if (p.x!=0 &&  p.y==0) {
		for (i=0;i<v.size()-1;i=i+1)
			if (b==v[i].y && (a-v[i].x)%p.x==0 && (a-v[i].x)/p.x>=0) {
				printf("Yes");
				return;
			}
		printf("No");
		return;
	}
	if (p.x!=0 && p.y!=0) {
		for (i=0;i<v.size()-1;i=i+1)
			if ((a-v[i].x)%p.x==0 && (a-v[i].x)/p.x>=0 && (b-v[i].y)%p.y==0 && (a-v[i].x)/p.x==(b-v[i].y)/p.y) {
				printf("Yes");
				return;
			}
		printf("No");
		return;
	}	
}
int main(void) {
	init();
	move();
	return 0;
}