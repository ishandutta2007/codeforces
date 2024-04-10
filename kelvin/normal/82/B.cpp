#include <stdio.h>
#include <algorithm> 
#include <map>
#define MAXN 205
#define MAXS (MAXN*MAXN/2)

using namespace std;

class List {
	public:
		int x,l,s[2];
		const bool operator<(const List &b) const {
			return s[0]<b.s[0]||s[0]==b.s[0]&&s[1]<b.s[1];
		}
};

int nn,setn,vn;
int sz[MAXS],mb[MAXS][MAXN];
int val[MAXS*MAXN];
List arr[MAXS*MAXN];
map<int,int> mp;

inline void solve() {
	int i,j,x;
	if(nn==2) {
		printf("%d %d\n",1,mb[0][0]);
		printf("%d",sz[0]-1);
		for(j=1;j<sz[0];j++)
			printf(" %d",mb[0][j]);
		puts("");
		return;
	}
	for(i=0;i<vn;i++){
		arr[i].x=val[i];
		arr[i].l=0;
		//printf("<%d>",val[i]);
	}
	for(i=0;i<setn;i++) {
		for(j=0;j<sz[i];j++) {
			x=mp[mb[i][j]];
			//printf("(%d)",x);
			if(arr[x].l<2)	arr[x].s[arr[x].l++]=i;
		}
	}
	std::sort(arr,arr+vn);
	//for(i=0;i<vn;i++)
	//	printf("> %d %d %d\n",arr[i].x,arr[i].s[0],arr[i].s[1]);
	for(i=0;i<vn;i=j) {
		for(j=i+1;j<vn&&!(arr[i]<arr[j]);j++);
		printf("%d",j-i);
		for(x=i;x<j;x++)
			printf(" %d",arr[x].x);
		puts("");
	}
}

int main(void)
{
	int i,j;
	while(scanf("%d",&nn)==1) {
		setn=nn*(nn-1)/2;
		vn=0;
		mp.clear();
		for(i=0;i<setn;i++) {
			scanf("%d",sz+i);
			for(j=0;j<sz[i];j++) {
				scanf("%d",mb[i]+j);
				if(mp.find(mb[i][j])==mp.end()) {
					mp[mb[i][j]]=vn;
					val[vn++]=mb[i][j];
				}
			}
		}
		solve();
		//puts("-");
	}
}