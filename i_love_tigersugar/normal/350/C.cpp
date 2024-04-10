#include<bits/stdc++.h>
#define MAX   100100
#define x   first
#define y   second
using namespace std;
typedef pair<int,int> ii;
struct cmd {
	int type;
	int time;
	char dir;
	cmd(){}	
	cmd(const int &t,const int &k,const char &c) {
		type=t;time=k;dir=c;
	}
	void print(void) const {
		if (type==1) printf("%d %d %c\n",type,time,dir);
		else printf("%d\n",type);
	}
};
ii a[MAX];
int n;
vector<cmd> res;
int iabs(const int &x) {
	if (x<0) return (-x); else return (x);
}
bool cmpdis(const int &x,const int &y) {
	if (iabs(x)<iabs(y)) return (true);
	if (iabs(x)>iabs(y)) return (false);
	return (x<y);
}
bool cmp(const ii &a,const ii &b) {
	if (cmpdis(a.x,b.x)) return (true);
	if (cmpdis(b.x,a.x)) return (false);
	return (cmpdis(a.y,b.y));
}
void init(void) {
	scanf("%d",&n);
	int i;
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&a[i].x);
		scanf("%d",&a[i].y);
	}
}
void move(const int &x,const int &y) {
	if (x<0) res.push_back(cmd(1,-x,'L'));
	if (x>0) res.push_back(cmd(1,x,'R'));
	if (y<0) res.push_back(cmd(1,-y,'D'));
	if (y>0) res.push_back(cmd(1,y,'U'));
	res.push_back(cmd(2,0,'#'));
	if (y<0) res.push_back(cmd(1,-y,'U'));
	if (y>0) res.push_back(cmd(1,y,'D'));
	if (x<0) res.push_back(cmd(1,-x,'R'));
	if (x>0) res.push_back(cmd(1,x,'L'));
	res.push_back(cmd(3,0,'#'));
}
void process(void) {
	res.clear();
	sort(&a[1],&a[n+1],cmp);
	int i;
	for (i=1;i<=n;i=i+1) move(a[i].x,a[i].y);
	printf("%d\n",res.size());
	for (i=0;i<res.size();i=i+1) res[i].print();
}
int main(void) {
	init();
	process();
	return 0;
}