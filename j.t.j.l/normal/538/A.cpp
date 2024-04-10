#include<bits/stdc++.h>

using namespace std;

char s[2000];

int main(){
	scanf("%s", s);
	int tot = 0;
	char ss[11] = "CODEFORCES";
	int l = strlen(s);
	for(int i = 0; i < strlen(s) && i < 10; i++)
		if (s[i] == ss[i])
			tot++;
		else
			break;
//	cout<<tot<<endl;
	for(int i = 0; i < l && i < 10; i++)
		if (s[l - i - 1] == ss[9 - i])
			tot++;
		else
			break;
	if (tot >= 10)
		puts("YES");
	else
		puts("NO");
	return 0;
}