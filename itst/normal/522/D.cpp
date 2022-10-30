#include<bits/stdc++.h>
#define MAXN 500001
using namespace std;

inline int read(){
	int a = 0;
	bool f = 0;
	char c = getchar();
	while(!isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

int output[13];
inline void print(int x){
	if(x == -1){
		putchar('-');
		putchar('1');
	}
	else{
		int dirN = 0;
		while(x){
			output[dirN++] = x % 10;
			x /= 10;
		}
		while(dirN)
			putchar(output[--dirN] + 48);
	}
	putchar('\n');
}

deque < int > qFir , qSec;
map < int , int > lsh;	
int firApp[MAXN] , Tree[MAXN << 2] , cntLSH , N;

inline void change(int dir , int now , int l , int r , int pri){
	if(l == r){
		Tree[now] = pri;
		return;
	}
	if(dir <= l + r >> 1)
		change(dir , now << 1 , l , l + r >> 1 , pri);
	else
		change(dir , now << 1 | 1 , (l + r >> 1) + 1 , r , pri);
	Tree[now] = min(Tree[now << 1] , Tree[now << 1 | 1]);
}

inline int get(int L , int R , int l , int r , int now){
	if(l >= L && r <= R)
		return Tree[now];
	int minN = 0x3f3f3f3f;
	if(l + r >> 1 >= L)
		minN = min(minN , get(L , R , l , l + r >> 1 , now << 1));
	if(l + r >> 1 < R)
		minN = min(minN , get(L , R , (l + r >> 1) + 1 , r , now << 1 | 1));
	return minN;
}

inline int getLSH(int dir){
	if(lsh.count(dir))
		return lsh.find(dir)->second;
	else{
		lsh.insert(make_pair(dir , ++cntLSH));
		return cntLSH;
	}
}

int main(){
	memset(Tree , 0x3f , sizeof(Tree));
	N = read();
	int M = read();
	for(int i = 1 ; i <= N ; i++){
		int t = getLSH(read());
		if(firApp[t])
			if(qFir.empty() || qFir.back() < firApp[t]){
				qFir.push_back(firApp[t]);
				qSec.push_back(i);
			}
		firApp[t] = i;
	}
	int sizeQ = qFir.size() - 1;
	for(int i = 0 ; i <= sizeQ ; i++)
		change(i , 1 , 0 , sizeQ , qSec[i] - qFir[i]);
	while(M--){
		int a = read() , b = read();
		int m = lower_bound(qFir.begin() , qFir.end() , a) - qFir.begin() , n = upper_bound(qSec.begin() , qSec.end() , b) - qSec.begin() - 1;
		if(m > n)
			print(-1);
		else
			print(get(m , n , 0 , sizeQ , 1));
	}
	return 0;
}