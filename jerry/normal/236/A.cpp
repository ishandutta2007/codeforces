#include <cstdio>
#include <cstring>

bool username[26];
char name[102];

int main()
{
	int ans = 0;
	scanf("%s", name);
	int len = strlen(name);
	for (int i = 0;i < len;i++) username[(int)(name[i]-'a')] = true;
	for (int i = 0;i < 26;i++) if (username[i])
		ans++;
	printf("%s\n", (ans%2)?"IGNORE HIM!":"CHAT WITH HER!");
	return 0;
}