#include <cstdio>
#include <map>
#include <set>
using namespace std;

int main()
{
     int n, k, i;
     int a[100000];
     map <int, int> mp;
     set <int> s;
     map <int, int>::iterator it;

     scanf("%d %d", &n, &k);

     for (i = 0; i < n; i++) scanf("%d", &a[i]);

     for (i = 0; i < k; i++) mp[a[i]]++;

     for (it = mp.begin(); it != mp.end(); it++) {
	  if (it->second == 1) s.insert(it->first);
     }

     for (i = 0; i < n - k + 1; i++) {
	  if (s.size() > 0) {
	       printf("%d\n", *(s.rbegin()));
	  } else {
	       puts("Nothing");
	  }

	  mp[a[i]]--;

	  if (mp[a[i]] == 0) {
	       s.erase(a[i]);
	  } else if (mp[a[i]] == 1) {
	       s.insert(a[i]);
	  }

	  if (i < n - k) {
	       mp[a[i + k]]++;

	       if (mp[a[i + k]] == 1) {
		    s.insert(a[i + k]);
	       } else if (mp[a[i + k]] == 2) {
		    s.erase(a[i + k]);
	       }
	  }
     }

     return 0;
}