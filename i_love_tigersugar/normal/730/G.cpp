#include<bits/stdc++.h>
#define C 200
using namespace std;
int start[C + 5] , finish[C + 5] , n;
bool valid(int x1,int y1,int x2,int y2){
	return (x2 > y1 || x1 > y2);
}
bool can_put(int pos,int x,int y){
	for(int i = 1 ; i < pos ; i++)
		if(!valid(x , y , start[i] , finish[i]))	return false;
	return true;
}
main(){
//	freopen("test.inp","r",stdin);
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++){
		int s , d;
		scanf("%d %d",&s,&d);
		if(can_put(i , s , s + d - 1)){
			start[i] = s ; finish[i] = s + d - 1;
			continue;
		}
		if(can_put(i , 1 , d)){
			start[i] = 1 ; finish[i] = d;
			continue;
		}
		start[i] = 2e9;
		for(int j = 1 ; j < i ; j++)	if(can_put(i , finish[j] + 1 , finish[j] + d)){
			start[i] = min(start[i] , finish[j] + 1);
		}	
		finish[i] = start[i] + d - 1;
	}
	for(int i = 1 ; i <= n ; i++)	printf("%d %d\n",start[i],finish[i]);
}