#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
     vector <int> v1, v2;
     char s[2];
     int x, i;
     long long min = 1000000000000000000; 

     for (i = 0; i < 4; i++) {
	  scanf("%d", &x);

	  v1.push_back(x);
     }

     for (i = 0; i < 3; i++) {
	  scanf("%s", s);

	  if (s[0] == '+') {
	       v2.push_back(0);
	  } else {
	       v2.push_back(1);
	  }
     }

     sort(v1.begin(), v1.end());

     do {
	  vector <int> a;

	  if (v2[0] == 0) {
	       a.push_back(v1[0] + v1[1]);
	  } else {
	       a.push_back(v1[0] * v1[1]);
	  }

	  a.push_back(v1[2]);
	  a.push_back(v1[3]);

	  sort(a.begin(), a.end());

	  do {
	       long long x, y;

	       if (v2[1] == 0) {
		    x = a[0] + a[1];
	       } else {
		    x = (long long)a[0] * a[1];
	       }

	       y = a[2];

	       if (v2[2] == 0) {
		    x += y;
	       } else {
		    x *= y;
	       }

	       if (x < min) min = x;
	  } while (next_permutation(a.begin(), a.end()));
     } while (next_permutation(v1.begin(), v1.end()));

     printf("%I64d\n", min);

     return 0;
}