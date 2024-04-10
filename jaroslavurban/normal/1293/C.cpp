#include <stdio.h>
#include <stdlib.h>
#include <iostream>


int isBlocked(int i, int isLava[3][2]){
	// printf("%d %d %d\n", i-1, isLava[i-1][0], isLava[i-1][1]);
	// printf("%d %d %d\n", i, isLava[i][0], isLava[i][1]);
	if ((isLava[i][0] && isLava[i][1]) ||
		(i > 0 && isLava[i][0] && isLava[i-1][1]) ||
		(i > 0 && isLava[i][1] && isLava[i-1][0]))
		return 1;
	return 0;
}


int updateBlock(int y, int *n_blocked, int *blocked, int isLava[3][2]){
	int bloc = blocked[y];
	// printf("%d %d\n", bloc, y);
	if ((blocked[y] = isBlocked(y, isLava)))
		*n_blocked += !bloc;
	else
		*n_blocked -= bloc;
	return 0;
}


int main(){
	int n, q;
	std::cin >> n >> q;
	int blocked[n+1] = {};
	int isLava[n+1][2] = {};
	int n_blocked = 0;
	for (int i = 0; i < q; i++){
		int x, y;
		std::cin >> y >> x;
		isLava[x][y-1] = !isLava[x][y-1];
		updateBlock(x, &n_blocked, blocked, isLava);
		if (x < n)
			updateBlock(x+1, &n_blocked, blocked, isLava);
		if (n_blocked)
			printf("NO\n");
		else
			printf("YES\n");
	}
}