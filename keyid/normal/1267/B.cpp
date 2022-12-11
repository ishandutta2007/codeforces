#include<bits/stdc++.h>
using namespace std;
char s[300011];
int main(){
	scanf("%s",s+1); int n=strlen(s+1);
	static vector<pair<char,int>> q;
	for (int i=1;i<=n;++i) if (s[i]==s[i-1])
		++q.back().second;else q.emplace_back(s[i],1);
	if (q.size()%2==0){
		puts("0"); exit(0);
	}
	int mid=q.size()/2;
	for (int i=0;i<mid;++i)
		if (q[i].first!=q[2*mid-i].first || q[i].second+q[2*mid-i].second<3){
			puts("0"); exit(0);
		}
	if (q[mid].second<2){
		puts("0"); exit(0);
	}
	printf("%d\n",q[mid].second+1);
}