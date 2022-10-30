#include<bits/stdc++.h>
using namespace std;

int main(){
    int N , maxN , minN , cnt = 0;
    cin >> N >> maxN;
    minN = maxN;
    for(int i = 2 ; i <= N ; i++){
    	int a;
    	cin >> a;
    	if(a > maxN){
    		maxN = a;
    		++cnt;
		}
		if(a < minN){
			minN = a;
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}