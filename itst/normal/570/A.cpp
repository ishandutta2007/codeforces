#include<bits/stdc++.h>
using namespace std;
int pot[101];
int main(){
    int N , M , maxN = 0 , maxD;
    for(cin >> N >> M ; M ; M--)
    {
    	int maxV = -1 , maxI;
    	for(int i = 1 ; i <= N ; i++){
    		int a;
    		cin >> a;
    		if(maxV < a){
    			maxV = a;
    			maxI = i;
			}
		}
		pot[maxI]++;
	}
	for(int i = 1 ; i <= N ; i++)
		if(maxN < pot[i])	maxN = pot[maxD = i];
	cout << maxD;
    return 0;
}