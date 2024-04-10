#include <iostream>
#include <cmath>
#include <cstdio>
#include <string.h>
using namespace std;
#define uint unsigned int 
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define INF 999999999
#define ms(d) memset(d,0,sizeof(d))

uint n,q;
ll tree[800020];
ll lazy[800020];
ll data[800020];

void build(uint lhs,uint rhs,uint pos){
	if(lhs == rhs) tree[pos] = data[lhs];
	else{
		uint mid = (lhs+rhs) / 2;	//[>w<]:rhs >>
		build(lhs,mid,pos*2);
		build(mid+1,rhs,pos*2+1);
		tree[pos] = min(  tree[pos*2]  ,  tree[pos*2+1]);
	}
}

void inc(uint gl,uint gr,uint l,uint r,uint pos,ll v){	//[>w<]:"g" means "goal" !
	if(l > gr  ||  r < gl) return;
	else if(gl <= l  &&  r <= gr) lazy[pos] += v;
	else{
		uint mid = (l+r) / 2;
		inc(gl,gr,l,mid,pos*2,v);
		inc(gl,gr,mid+1,r,pos*2+1,v);
		tree[pos] = min(  tree[pos*2]+lazy[pos*2]  ,  tree[pos*2+1]+lazy[pos*2+1]  );
	}
}
ll rmq(uint gl,uint gr,uint l,uint r,uint pos){	//[>w<]:"g" means "goal" ! +1
	if(l > gr  ||  r < gl) return INF;
	if(gl <= l  &&  r <= gr) return tree[pos] + lazy[pos];
	uint mid = (l+r) / 2;
	return min(  rmq(gl,gr,l,mid,pos*2)  ,  rmq(gl,gr,mid+1,r,pos*2+1)  ) + lazy[pos];
}


int main(){
//	freopen("inp.txt","r",stdin);
	ms(tree);
	ms(lazy);
	
	scanf("%d",&n);
	for(uint i = 1;i <= n;i++)
		cin >> data[i];
	
	build(1,n,1);
	
	scanf("%d\n",&q);
	for(uint qi = 1;qi <= q;qi++){
		char inp[233];
		uint l,r;
		int v;
		cin.getline(inp,sizeof(inp));
		if(sscanf(inp,"%d %d %d",&l,&r,&v) == 3){
			l += 1;
			r += 1;
			if(l <= r) inc(l,r,1,n,1,v);	//[>w<]:"<="!
			else{
				inc(l,n,1,n,1,v);
				inc(1,r,1,n,1,v);
			}
		}else{	//[>w<]:"<="! +1
			l += 1;
			r += 1;
			if(l <= r) cout << rmq(l,r,1,n,1) << endl;
			else cout << min(  rmq(l,n,1,n,1)  ,  rmq(1,r,1,n,1)  ) << endl;
		}
	}
	return 0;
	
}