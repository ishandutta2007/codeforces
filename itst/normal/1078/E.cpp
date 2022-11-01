#include<bits/stdc++.h>
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

char mod[] = "ludr";
int cnt = 0;
void move_no_empty(int x , int times = 1){
	cnt += times * 4;
	while(times--)
		printf("%cs%ct" , mod[x] , mod[3 - x]);
}

void move_one(int x , int times = 1){
	cnt += times * 4;
	while(times--)
		printf("%c%cst" , mod[x] , mod[3 - x]);
}

void move_zero(int x , int times = 1){
	cnt += times * 3;
	while(times--)
		printf("%c%ct" , mod[x] , mod[3 - x]);
}

void move(int x , int times = 1){
	cnt += times;
	while(times--)
		printf("%c" , mod[x]);
}

void copy(int x , int times = 1){
	cnt += times * 5;
	while(times--)
		printf("%c10%ct" , mod[x] , mod[3 - x]);
}

void put(int x){
	cnt++;
	printf("%d" , x);
}

void era(){
	cnt++;
	putchar('e');
}

int main(){
	move_no_empty(0 , 32);
	for(int i = 1 ; i <= 32 ; ++i)
		put(0),move(0);
	move(3);
	move_no_empty(3 , 64);
	move(0);move(1);
	move_no_empty(0 , 32);
	for(int i = 1 ; i <= 32 ; ++i)
		put(0),move(0);
	move(3);
	move_no_empty(3 , 64);
	move(0);move(1);
	put(0);move(2 , 2);
	for(int i = 1 ; i <= 32 ; ++i){
		move(1);copy(3);
		move(2);move(0);copy(3 , 2);
		move(2);move(3);
		move(3);era();move(0);
		put(1);move(0);put(0);move(0);put(1);move(0);put(0);
		move(1 , 3);
		move_one(3);move(2);move_one(3);move(2);move_one(3);move(2);
		for(int j = 1 ; j <= 4 ; ++j){
			move_no_empty(3);
			move_no_empty(0);
			copy(3);
		}
		move(0);
		copy(0 , 3);
		copy(2);
		move(1);
		put(0);move(3);put(0);move(3);put(1);move(3);put(1);
		move(0 , 3);
		move(1 , 3);
		move_one(3);move(2);move_one(3);move(2);move_one(3);move(2);
		for(int j = 1 ; j <= 4 ; ++j){
			move_no_empty(3);
			move_no_empty(0);
			copy(3);
		}
		move(0);
		copy(0 , 3);copy(1 , 3);copy(0);
		move(2 , 2);
	}
	move(2 , 2);
	move(3);
	move_zero(3 , 32);
	return 0;
}