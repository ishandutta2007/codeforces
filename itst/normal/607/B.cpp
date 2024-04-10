#include<bits/stdc++.h>
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
inline int min(int a , int b){
	return a < b ? a : b;
}
int num[502] , minN[502][502];
int main(){
	int N = read();
	for(int i = 1 ; i <= N ; i++){
		num[i] = read();
		minN[i][i] = minN[i][i - 1] = 1;
	}
	minN[N + 1][N] = 1;
	for(int i = N - 1 ; i ; i--)
		for(int j = i + 1 ; j <= N ; j++){
			minN[i][j] = minN[i + 1][j];
			for(int k = i + 1 ; k <= j ; k++)
				if(num[i] == num[k])
					minN[i][j] = min(minN[i][j] , minN[i + 1][k - 1] + minN[k + 1][j] - 1 - (k == j));
			minN[i][j]++;
		}
	cout << minN[1][N];
	return 0;
}