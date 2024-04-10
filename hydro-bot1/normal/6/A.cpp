// Hydro submission #63076285857e326068ab5295@1661428357518
#include<bits/stdc++.h>
using namespace std;
int t[10];
int main(){
	scanf("%d%d%d%d",&t[1],&t[2],&t[3],&t[4]);
	sort(t+1,t+5);
	if(t[1]+t[2]>t[3]||t[1]+t[2]>t[4]||t[1]+t[3]>t[4]||t[2]+t[3]>t[4])		
		printf("TRIANGLE");
	else if(t[1]+t[2]==t[3]||t[1]+t[2]==t[4]||t[1]+t[3]==t[4]||t[2]+t[3]==t[4]||t[1]==0||t[2]==0||t[3]==0||t[4]==0)
		printf("SEGMENT");
	else
		printf("IMPOSSIBLE");
	return 0;
}