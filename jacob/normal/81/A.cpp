#include <cstdio>
#include <vector>
using namespace std;

char str[300000];

int main(void) {
	vector<char> res;
	res.push_back('$');
	scanf("%s", str);
	for (char* ch = str; *ch; ch++) {
		if (res.back() == *ch)
			res.pop_back();
		else
			res.push_back(*ch);
	}
	res.push_back(char(0));
	printf("%s\n", &res[1]);
	return 0;
}