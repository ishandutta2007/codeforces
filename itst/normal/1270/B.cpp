#include<bits/stdc++.h>
using namespace std;

int main(){
	static int arr[200003] , N , T;
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
		int id = 0; for(int i = 1 ; i < N ; ++i) if(abs(arr[i] - arr[i + 1]) > 1) id = i;
		if(!id) puts("NO");
		else printf("YES\n%d %d\n" , id , id + 1);
	}
	return 0;
}