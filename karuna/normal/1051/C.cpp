#include <bits/stdc++.h>

int main(){
	int n;
	scanf("%d", &n);
	
	int i, arr[100], count[101] = {0,};
	
	for (i=0;i<n;i++){
		scanf("%d", &arr[i]);
		count[arr[i]]++;
	}
	
	int c=0;
	char group[101];
	for (i=0;i<n;i++){
		if (count[arr[i]] == 1) {
			if (c%2==0) group[i] = 'A';
			else group[i] = 'B';
			c++;
		}
	}
	for (i=0;i<n;i++){
		if (count[arr[i]] == 2){
			group[i] = 'A';
		}
		if (count[arr[i]] >= 3){
			if (c%2 == 0) {
				group[i] = 'A';
			}
			else {
				group[i] = 'B';
				count[arr[i]] = -2;
				c++;
			}
		}
		else if (count[arr[i]] == -2) {
			group[i] = 'A';
		}
	}
	
	if (c%2==1) printf("NO");
	else {
		printf("YES\n");
		for (i=0;i<n;i++){
			printf("%c", group[i]);
		}
	}
	
}