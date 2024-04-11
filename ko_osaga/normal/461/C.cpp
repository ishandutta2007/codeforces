#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

int arr[100005];
int s, e;
int n, q;

struct bit{
	int tree[100005];
	int lim;
	void init(int n){
		lim = n+2;
	}
	void add(int x, int v){
		x += 2;
		while(x <= lim){
			tree[x] += v;
			x += x & -x;
		}
	}
	int q(int x){
		x += 2;
		int r = 0;
		while(x){
			r += tree[x];
			x -= x & -x;
		}
		return r;
	}
	int rsum(int s, int e){
		return abs(q(e) - q(s-1));
	}
}bit;

int revered = 0;
int main(){
	scanf("%d %d",&n,&q);
	bit.init(n);
	for(int i=1; i<=n; i++){
		arr[i] = 1;
		bit.add(i,1);
	}	
	s = 0, e = n;
	for(int i=0; i<q; i++){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int x;
			scanf("%d",&x);
			if(s > e){
				x = s - x;
				int m = (s+e)/2;
				if(x >= m){
					for(int i=x+1; i<=s; i++){
						int arri = bit.rsum(i,i);
						bit.add(2*x+1-i,arri);
						bit.add(i,-arri);
					}
					s = x;
				}
				else{
					for(int i=x; i>e; i--){
						int arri = bit.rsum(i,i);
						bit.add(2*x+1-i,arri);
						bit.add(i,-arri);
					}
					e = x;
					swap(s,e);
				}
			}
			else{
				x += s;
				int m = (s+e)/2;
				if(x <= m){
					for(int i=x; i>s; i--){
						int arri = bit.rsum(i,i);
						bit.add(2*x+1-i,arri);
						bit.add(i,-arri);
					}
					s = x;
				}
				else{
					for(int i=x+1; i<=e; i++){
						int arri = bit.rsum(i,i);
						bit.add(2*x+1-i,arri);
						bit.add(i,-arri);
					}
					e = x;
					swap(s,e);
				}
			}
		}
		else if(t == 2){
			int st, ed;
			scanf("%d %d",&st,&ed);
			if(s > e){
				st = s - st;
				ed = s - ed;
			}
			else{
				st += s;
				ed += s;
			}
			printf("%d\n",bit.rsum(st+1,ed));
		}
	}
}