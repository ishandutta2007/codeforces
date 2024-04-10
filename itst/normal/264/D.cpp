#include<bits/stdc++.h>
using namespace std;

char s1[2000001] , s2[2000001];
int l1 , l2 , p1 , p2 , pot[27][27];
long long ans;

inline void input(){
	scanf("%s %s" , s1 , s2);
	l1 = strlen(s1);
	l2 = strlen(s2);
}

inline void work(){
	for(int i = 0 ; i < l1 ; i++){
		while(p2 < l2 - 1 && s2[p2] != s1[i]){
			p2++;
			pot[s2[p2] - 'A'][s2[p2 - 1] - 'A']++;
		}
		ans += p2 - p1 + 1 - (i ? (s1[i - 1] != s1[i]) * pot[s1[i - 1] - 'A'][s1[i] - 'A'] : 0);
		if(s2[p1] == s1[i]){
    		if(p1 < l2 - 1)
			    pot[s2[p1 + 1] - 'A'][s2[p1] - 'A']--;
			p1++;
		}
		if(p2 < l2 - 1){
			p2++;
			pot[s2[p2] - 'A'][s2[p2 - 1] - 'A']++;
		}
	}
}

inline void output(){
	cout << ans;
}

int main(){
	input();
	work();
	output();
	return 0;
}