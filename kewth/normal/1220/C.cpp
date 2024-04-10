#if 0
date +%Y.%m.%d


        
          
        
            
           
        
          
   CopyRight :)
      
#endif
#include <cstdio>
#include <cstring>
#define debug(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 500005;
char s[maxn];

int main () {
	scanf("%s", s + 1);
	int n = int(strlen(s + 1));

	int min = 256;
	for (int i = 1; i <= n; i ++)
		if (s[i] <= min) {
			puts("Mike");
			min = s[i];
		} else
			puts("Ann");
}