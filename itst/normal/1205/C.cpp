#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

#define id(i,j) (((i) - 1) * N + (j))
const int _ = 50*50 + 7;
int fa[_ * 2] , ans[53][53] , N; int arr[6][6];

int qry(int x1 , int y1 , int x2 , int y2){
	printf("? %d %d %d %d\n" , x1 , y1 , x2 , y2); fflush(stdout);
	int ans; scanf("%d" , &ans); return ans;
}

int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}
void link(int x1 , int y1 , int x2 , int y2){
	if(qry(x1 , y1 , x2 , y2)){
		fa[find(id(x1 , y1))] = find(id(x2 , y2));
		fa[find(id(x1 , y1) + N * N)] = find(id(x2 , y2) + N * N);
	}
	else{
		fa[find(id(x1 , y1))] = find(id(x2 , y2) + N * N);
		fa[find(id(x1 , y1) + N * N)] = find(id(x2 , y2));
	}
}

int calc(int x1 , int y1 , int x2 , int y2 , int val){
	for(int i = x1 ; i <= x2 ; ++i)
		for(int j = y1 ; j <= y2 ; ++j)
			if((i + j) & 1)
				arr[i - x1][j - y1] = val ^ 1 ^ (find(id(i , j)) == find(id(1 , 2)));
			else arr[i - x1][j - y1] = ans[i][j];
	x2 -= x1; y2 -= y1;
	if(arr[x2][y2] != arr[0][0]) return 0;
	else
		for(int i = 0 ; i <= 1 ; ++i)
			for(int j = 0 ; j <= 1 ; ++j)
				if(x2 - (i == 0) - (j == 0) >= 0 && y2 - i - j >= 0 && arr[i == 0][i == 1] == arr[x2 - (j == 0)][y2 - (j == 1)])
					return 1;
	return 0;
}

void work(int val){
	for(int i = 1 ; i <= N ; ++i)
		for(int j = (i & 1 ? 2 : 1) ; j <= N ; j += 2)
			ans[i][j] = val ^ (find(id(i , j)) == find(id(1 , 2))) ^ 1;
}

int main(){
	scanf("%d" , &N); for(int i = 1 ; i <= 2 * N * N ; ++i) fa[i] = i;
	fa[id(1 , 1)] = id(N , N) + N * N;
	fa[id(1 , 1) + N * N] = id(N , N);
	for(int i = 1 ; i <= N ; i += 2){
		for(int j = 1 ; j < N ; j += 2){
			link(i , j , i , j + 2);
			if(i != N)
				link(i , j , i + 1 , j + 1);
		}
		if(i != N && i + 2 != N) link(i + 1 , 2 , i + 2 , 3);
	}
	for(int i = 1 ; i <= N ; ++i)
		for(int j = (i & 1 ? 1 : 2) ; j <= N ; j += 2)
			ans[i][j] = find(id(1 , 1)) == find(id(i , j));
	for(int i = 1 ; i <= N ; i += 2){
		for(int j = 2 ; j < N ; j += 2){
			if(j + 2 <= N) link(i , j , i , j + 2);
			if(i + 1 <= N) link(i , j , i + 1 , j + 1);
		}
		if(i != N){link(i + 1 , 1 , i + 1 , 3); link(i + 1 , 1 , i + 2 , 2);}
	}
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= N ; ++j)
			for(int k = 3 ; k >= 0 ; --k)
				if(i + k <= N && j + 3 - k <= N){
					int p = calc(i , j , i + k , j + 3 - k , 0) , q = calc(i , j , i + k , j + 3 - k , 1);
					if(p ^ q){
						int t = qry(i , j , i + k , j + 3 - k); work(p ^ t);
						cout << "!" << endl;
						for(int i = 1 ; i <= N ; ++i){
							for(int j = 1 ; j <= N ; ++j)
								cout << ans[i][j];
							cout << endl;
						}
						return 0;
					}
				}
	return 0;
}