#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int i, j, k;
int arr[100000];
char str1[100000];


int main(){
	scanf("%d", &n);

	for (i=0;i<n;i++){
		int a[3] = {-1, -1, -1};
		scanf("%s", str1);
		int k = strlen(str1);
		for (j=0;j<k;j++){
			if (str1[j] >= 'a' && str1[j] <= 'z') a[0]=j;
			if (str1[j] >= 'A' && str1[j] <= 'Z') a[1]=j;
			if (str1[j] >= '0' && str1[j] <= '9') a[2]=j;
		}
		
		for (j=k-1;j>=0;j--){
			if (a[0] == -1 || a[1] == -1 || a[2] == -1){
				if (j!=a[0] && j!=a[1] && j!=a[2]) {
					if (a[0] == -1) {
						str1[j] = 'a';
						a[0] = j;
						continue;
					}
					if (a[1] == -1) {
						str1[j] = 'A';
						a[1] = j;
						continue;
					}
					if (a[2] == -1) {
						str1[j] = '0';
						a[2] = j;
						continue;
					}
				}
			}
			else break;
		}
		printf("%s\n", str1);
	}
	
	
	return 0;
}