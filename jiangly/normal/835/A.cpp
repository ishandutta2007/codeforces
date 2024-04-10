#include<bits/stdc++.h>
const int N=55+5;
int s,v_1,v_2,t_1,t_2,T_1,T_2;
int main(){
	scanf("%d%d%d%d%d",&s,&v_1,&v_2,&t_1,&t_2);
	T_1=s*v_1+2*t_1;
	T_2=s*v_2+2*t_2;
	if(T_1<T_2){
		puts("First");
	}else if(T_1>T_2){
		puts("Second");
	}else{
		puts("Friendship");
	}
	return 0;
}