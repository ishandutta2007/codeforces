#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char basestring[1000100];
char newstring[1001000];
int pi[1000100];
int basestrlen;
int N, M;
int main()
{
	scanf("%d", &N);
	int i;
	scanf("%s", basestring);
	basestrlen = strlen(basestring);
	N--;
	while(N--)
	{
		scanf("%s", newstring);
		int l = strlen(newstring);
		int j = 0;
		for (i = 1; i < l; i++)
		{
			while (j && (newstring[i] != newstring[j]))
				j = pi[j - 1];
			if (newstring[i] == newstring[j])
				pi[i] = ++j;
		}
		j = 0;
		for (i = max(basestrlen-l,0); i < basestrlen; i++)
		{
			while (j && (basestring[i] != newstring[j]))
				j = pi[j - 1];
			if (basestring[i] == newstring[j])
			{
					j++;
			}
		}
		for (i = 0; i < l-j; i++)
		{
			basestring[basestrlen + i] = newstring[i + j];
		}
		memset(newstring, 0, l);
		memset(pi, 0, 4 * l);
		basestrlen += l - j;
	}
	printf("%s", basestring);
}