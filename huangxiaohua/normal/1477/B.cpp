#include <bits/stdc++.h>
#define LL long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define N 200005
using namespace std;
int sum[N * 4], add[N * 4], col[N * 4], mul[N * 4];
void pushup(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void pushdown(int rt, int x){
    if(col[rt] != -1){
        add[rt<<1] = add[rt<<1|1] = 0;
        mul[rt<<1] = mul[rt<<1|1] = 1;
        sum[rt<<1] = col[rt] * (x - x / 2);
        sum[rt<<1|1] = col[rt] * (x / 2);
        col[rt<<1] = col[rt<<1|1] = col[rt];
        col[rt] = -1;
    }
    if(mul[rt] != 1){
        int c = mul[rt];
        mul[rt<<1] *= c;
        mul[rt<<1|1] *= c;
        sum[rt<<1] *= c;
        sum[rt<<1|1] *= c;
        add[rt<<1] *= c;
        add[rt<<1|1] *= c;
        mul[rt] = 1;
    }
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += add[rt] * (x - x / 2);
        sum[rt<<1|1] += add[rt] * (x / 2);
        add[rt] = 0;
    }
}
void build(int l, int r, int rt){
    if(l == r){
        scanf("%d", &sum[rt]);
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int l, int r, int rt, int a, int b, int c, int o){
    if(l >= a && r <= b){
        if(o == 1){//set
            add[rt] = 0;
            mul[rt] = 1;
            sum[rt] = c * (r - l + 1);
            col[rt] = c;
        }
        else if(o == 2){//cheng
            mul[rt] *= c;
            sum[rt] *= c;
            add[rt] *= c;
        }
        else{//jia
            add[rt] += c;
            sum[rt] += c * (r - l + 1);
        }
        return;
    }
    pushdown(rt, r-l+1);
    int m = l + r >> 1;
    if(a <= m) update(lson, a, b, c, o);
    if(b > m) update(rson, a, b, c, o);
    pushup(rt);
}
int query(int l, int r, int rt, int a, int b){
    if(l >= a && r <= b) return sum[rt];
    pushdown(rt, r-l+1);
    int m = l + r >> 1, ans = 0;
    if(a <= m) ans += query(lson, a, b);
    if(b > m) ans += query(rson, a, b);
    return ans;
}

int i, j, n, m, o, a, b, c, t,q,x,L,R;
int sb[200500],sb2[200500],que[200500][2];
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d%d",&n,&q);
    	for(i=1;i<=n;i++){
    		scanf("%1d",&sb[i]);
		}
		for(i=1;i<=n;i++){
    		scanf("%1d",&sb2[i]);
    		update(1,n,1,i,i,sb2[i],1);
		}
		for(i=1;i<=q;i++){
			scanf("%d%d",&que[i][0],&que[i][1]);
		}
		for(i=q;i>=1;i--){
			L=que[i][0];R=que[i][1];
			x=query(1,n,1,L,R);
			if((R-L+1)==(x*2)){puts("NO");goto aaa;}
			if((R-L+1)>(x*2)){update(1,n,1,L,R,0,1);}
			else{update(1,n,1,L,R,1,1);}
		}
		for(i=1;i<=n;i++){
			if(query(1,n,1,i,i)!=sb[i]){puts("NO");goto aaa;}
		}
		puts("YES");
		aaa:;
	}
}