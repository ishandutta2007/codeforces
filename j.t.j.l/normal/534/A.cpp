#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	if (n >= 6){
		cout<<n<<endl;
		if (n % 2 == 1)
			printf("%d ", n);
		for(int i = 1; i <= n / 2; i++){
			printf("%d ", i);
			printf("%d%c", i + n / 2, " \n"[i == n / 2]);
		}
	}
	else{
		if (n == 1) puts("1\n1\n");
		if (n == 2) puts("1\n1\n");
		if (n == 3) puts("2\n1 3\n");
		if (n == 4) puts("4\n3 1 4 2\n");
		if (n == 5) puts("5\n5 2 4 1 3\n");
	}
	return 0;
}