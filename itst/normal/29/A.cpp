#include<bits/stdc++.h>
using namespace std;

int num[101][2];

int main(){
	int N;
	cin >> N;
	for(int i = 1 ; i <= N ; i++)
		cin >> num[i][0] >> num[i][1];
	for(int i = 1 ; i <= N ; i++)
		for(int j = i + 1 ; j <= N ; j++)
			if(num[i][0] + num[i][1] == num[j][0] && num[j][0] + num[j][1] == num[i][0]){
				puts("YES");
				return 0;
			}
	puts("NO");
	return 0;
}