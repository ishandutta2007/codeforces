#include<bits/stdc++.h>
using namespace std;

char s[100010];
bool vis[129];
int maxN[129];

int main(){
    int p1 = 1 , p2 , minN , N , cnt = 0;
    scanf("%d %s" , &N , s + 1);
    minN = N;
    for(int i = 1 ; i <= N ; i++)
    	if(!vis[s[i]]){
			vis[s[i]] = 1;
			cnt++;
		}
	for(p2 = 1 ; p2 <= N ; p2++){
		maxN[s[p2]] = p2;
		while(p1 < p2 && maxN[s[p1]] != p1)
			p1++;
		if(vis[s[p2]]){
			vis[s[p2]] = 0;
			cnt--;
		}
		if(!cnt)
			minN = min(minN , p2 - p1 + 1);
	}
	cout << minN;
    return 0;
}