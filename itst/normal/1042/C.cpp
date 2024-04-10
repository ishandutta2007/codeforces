#include<bits/stdc++.h>
#define MAXN 200001
using namespace std;

int minFu , minFuDir , timesFu , cnt0;
bool if0[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("testdata.in" , "r" , stdin);
	//freopen("testdata.out" , "w" , stdout);
	int N;
	cin >> N;
	for(int i = 1 ; i <= N ; i++){
		int a;
		cin >> a;
		if(a < 0){
			timesFu++;
			if(!minFuDir || minFu < a){
				minFu = a;
				minFuDir = i;
			}
		}
		else
			if(a == 0){
				if0[i] = 1;
				cnt0++;
			}
	}
	if((timesFu == 1 && cnt0 == N - 1) || (!cnt0 && timesFu % 2 == 0) || cnt0 == N)
		for(int i = 1 ; i < N ; i++)
			printf("1 %d %d\n" , i , i + 1);
	else{
		int past = 1;
		if(cnt0){
			while(N && !if0[past])
				past++;
			for(int j = past + 1 ; j <= N ; j++)
				if(if0[j]){
					printf("1 %d %d\n" , past , j);
					past = j;
				}
			if(timesFu & 1)
				printf("1 %d %d\n" , minFuDir , past);
			printf("2 %d\n" , past);
		}
		else
			printf("2 %d\n" , minFuDir);
		past = 1;
		while(if0[past] || (timesFu % 2 && past == minFuDir))
			past++;
		for(int j = past + 1 ; j <= N ; j++)
			if(!if0[j] && (timesFu % 2 == 0 || j != minFuDir)){
				printf("1 %d %d\n" , past , j);
				past = j;
			}
	}
	return 0;
}