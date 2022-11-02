#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int k, n, i, j;
    char s[100001];
    vector <int> v[26];
    string ans = "";

    scanf("%s", s);

    scanf("%d", &k);

    n = strlen(s);

    if ((long long)n * (n + 1) / 2 < k) {
	puts("No such line.");

	return 0;
    }

    for (i = 0; i < n; i++) {
	v[s[i] - 'a'].push_back(i);
    }

    while (1) {
	long long sum = 0;
	long long p = 0;

	for (i = 0; i < 26; i++) {
	    if (sum + v[i].size() >= k) {
		ans += 'a' + i;

		printf("%s\n", ans.c_str());

		return 0;
	    }

	    for (j = 0; j < v[i].size(); j++) {
		sum += n - v[i][j];

		if (sum >= k) break;
	    }

	    if (j < v[i].size()) {
		vector <int> w[26];

		k -= p;
		k -= v[i].size();

		for (j = 0; j < v[i].size(); j++) {
		    if (v[i][j] + 1 < n) {
			w[s[v[i][j] + 1] - 'a'].push_back(v[i][j] + 1);
		    }
		}

		for (j = 0; j < 26; j++) v[j] = w[j];

		ans += 'a' + i;

		break;
	    }

	    p = sum;
	}
    }

    printf("%s\n", ans.c_str());

    return 0;
}