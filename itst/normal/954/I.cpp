#include<bits/stdc++.h>
#define eps 1e-2
#define ld long double
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	bool f = 0;
	char c = getchar();
	while(c != EOF && !isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(c != EOF && isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 265000;
char s1[MAXN] , s2[MAXN];
struct comp{
	ld x , y;

	comp(ld _x = 0 , ld _y = 0){
		x = _x;
		y = _y;
	}

	comp operator +(comp a){
		return comp(x + a.x , y + a.y);
	}

	comp operator -(comp a){
		return comp(x - a.x , y - a.y);
	}

	comp operator *(comp a){
		return comp(x * a.x - y * a.y , x * a.y + y * a.x);
	}
}A[MAXN] , B[MAXN];
const ld pi = acos(-1);
int fa[MAXN][7] , ans[MAXN] , dir[MAXN] , need;

inline void FFT(comp* a , int type){
    for(int i = 1 ; i < need ; ++i)
        if(i < dir[i])
            swap(a[i] , a[dir[i]]);
    for(int i = 1 ; i < need ; i <<= 1){
        comp wn(cos(pi / i) , type * sin(pi / i));
        for(int j = 0 ; j < need ; j += i << 1){
            comp w(1 , 0);
            for(int k = 0 ; k < i ; ++k , w = w * wn){
                comp x = a[j + k] , y = a[i + j + k] * w;
                a[j + k] = x + y;
                a[i + j + k] = x - y;
            }
        }
    }
}

bool cmp(ld a , ld b){
	return a - eps < b && a + eps > b;
}

int find(int dir , int x){
	return fa[dir][x] == x ? x : (fa[dir][x] = find(dir , fa[dir][x]));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("954I.in" , "r" , stdin);
	//freopen("954I.out" , "w" , stdout);
#endif
	scanf("%s%s" , s1 , s2);
	int l1 = strlen(s1) , l2 = strlen(s2);
	for(int i = 0 ; i < (l2 >> 1) ; ++i)
		swap(s2[i] , s2[l2 - i - 1]);
	need = 1;
	while(need < l1 + l2 - 1)
		need <<= 1;
	for(int i = 0 ; i <= l1 - l2 ; ++i)
		for(int j = 1 ; j <= 6 ; ++j)
			fa[i][j] = j;
	for(int i = 1 ; i < need ; ++i)
		dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
	for(int i = 0 ; i <= 5 ; ++i)
		for(int j = 0 ; j <= 5 ; ++j)
			if(i != j){
				for(int k = 0 ; k < need ; ++k){
					A[k].x = s1[k] == 'a' + i;
					A[k].y = 0;
				}
				for(int k = 0 ; k < need ; ++k){
					B[k].x = s2[k] == 'a' + j;
					B[k].y = 0;
				}
				FFT(A , 1);
				FFT(B , 1);
				for(int k = 0 ; k < need ; ++k)
					A[k] = A[k] * B[k];
				FFT(A , -1);
				for(int k = l2 - 1 ; k < l1 ; ++k)
					if(!cmp(A[k].x , 0))
						if(find(k - l2 + 1 , i + 1) != find(k - l2 + 1 , j + 1)){
							fa[k - l2 + 1][find(k - l2 + 1 , i + 1)] = find(k - l2 + 1 , j + 1);
							++ans[k - l2 + 1];
						}
			}
	for(int i = 0 ; i <= l1 - l2 ; ++i)
		printf("%d " , ans[i]);
	return 0;
}