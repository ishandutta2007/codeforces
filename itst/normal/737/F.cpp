#include<bits/stdc++.h>
#define INF 0x7fffffff
#define NO {puts("NO"); exit(0);}
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
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

struct P{
	int fr , sc , th , fo;
	P(int a , int b , int c , int d) : fr(a) , sc(b) , th(c) , fo(d){}
};
const int MAXN = 2010;
int st1[MAXN] , st2[MAXN] , step[MAXN * 2][2] , cnt , top1 , top2 , N , A , B , now_calc;
bool vis[MAXN];

bool check(int x){
	for(int i = 1 ; i <= x - 1 ; ++i)
		if(!vis[x])
			return 0;
	return 1;
}

inline void move1(int num , bool f = 1){
	if(f && st2[top2] - st1[top1 - num + 1] >= 2 && top2)
		NO
	for(int i = 1 ; i <= num ; ++i)
		vis[st2[++top2] = st1[top1 - num + i]] = 1;
	step[++cnt][0] = 1;
	step[cnt][1] = num;
	top1 -= num;
}

inline void move2(int num){
	now_calc = st2[top2] - 1;
	top2 -= num;
	step[++cnt][0] = 2;
	step[cnt][1] = num;
}

P calc(int lim){
	int p = top1 , p1 , befBeg = top1 , maxLen = 0 , befBefNum = INF , cnt = 1;
	bool link = 1;
	while(p && st1[p] != lim)
		--p;
	p1 = p;
	while(p1 <= top1 && st1[p1] == lim){
		++p1;
		--lim;
	}
	if(p1 > top1)
		return P(p , -1 , top1 - p + 1 , 1);
	p = top1 - 1;
	while(p){
		if(st1[p] != st1[p + 1] + 1){
			maxLen = max(maxLen , befBeg - p);
			if(befBefNum != INF && befBefNum != st1[p + 1] + 1)
				link = 0;
			befBefNum = st1[befBeg];
			if(st1[p] > st1[p + 1])
				break;
			befBefNum = st1[befBeg];
			befBeg = p;
			++cnt;
		}
		--p;
	}
	return P(p + 1 , link , maxLen , cnt);
}

inline int calcLen(){
	int p1 = top1;
	while(p1 && top1 - p1 == st1[p1] - st1[top1])
		--p1;
	return top1 - p1;
}

int main(){
	top1 = N = now_calc = read();
	A = read();
	B = read();
	for(int i = N ; i ; --i)
		st1[i] = read();
	while(now_calc)
		if(vis[now_calc]){
			for(int i = top2 ; i ; --i)
				if(st2[i] == now_calc)
					if(top2 - i + 1 > B)
						NO
					else{
						move2(top2 - i + 1);
						break;
					}
		}
		else{
			P k = calc(now_calc);
			k.fr = top1 - k.fr + 1;
			switch(k.sc){
			case -1:
				now_calc = st1[top1] - 1;
				for(int i = 1 ; i <= k.fr ; ++i)
					move1(1);
				for(int i = 1 ; i <= k.fr ; ++i)
					move2(1);
				break;
			case 0:
				if(k.fr > A)
					NO
				else
					move1(k.fr);
				break;
			case 1:
				if(A < k.th)
					if(k.fo >= 3)
						NO
					else
						if(k.fo == 1)
							for(int i = 1 ; i <= k.fr ; ++i)
								move1(i);
						else{
							int t = calcLen() , cut = max(max(k.fr - A , 0) , t - B);
							if(cut <= A && cut <= B + t - k.fr){
								if(cut)
									move1(cut);
								move1(k.fr - cut);
								break;
							}
							else{
								cut = max(max(1 , k.fr - A) , k.fr + t - B);
								if(cut <= A && cut <= B + t){
									move1(cut);
									move1(k.fr - cut);
									break;
								}
								else
									NO
							}
						}
				else
					if(B < k.fr)
						if(k.fo == 1)
							for(int i = 1 ; i <= k.fr ; ++i)
								move1(i);
						else
							if(k.fo >= 3){
								if(A < k.fr)
									NO
								move1(k.fr);
							}
							else{
								int t = calcLen() , cut = max(max(k.fr - A , 0) , t - B);
								if(cut <= A && cut <= B + t - k.fr){
									if(cut)
										move1(cut);
									move1(k.fr - cut);
									break;
								}
								else{
									cut = max(max(1 , k.fr - A) , k.fr + t - B);
									if(cut <= A && cut <= B + t){
										move1(cut);
										if(k.fr - cut)
											move1(k.fr - cut);
										break;
									}
									else
										NO
								}
							}
					else{
						k.fr = top1 - k.fr + 1;
						while(top1 >= k.fr)
							move1(calcLen());
					}
				break;
			}
		}
	puts("YES");
	printf("%d\n" , cnt);
	for(int i = 1 ; i <= cnt ; ++i)
		printf("%d %d\n" , step[i][0] , step[i][1]);
	return 0;
}