#include <cstdio>

char thing[10][16] = {
"O-|-OOOO",
"O-|O-OOO",
"O-|OO-OO",
"O-|OOO-O",
"O-|OOOO-",
"-O|-OOOO",
"-O|O-OOO",
"-O|OO-OO",
"-O|OOO-O",
"-O|OOOO-"};

int main()
{
	int num;
	scanf("%d", &num);
	if (num == 0)
	{
		printf("%s\n", thing[0]);
		return 0;
	}
	while (num > 0)
	{
		printf("%s\n", thing[num%10]);
		num /= 10;
	}
	return 0;
}