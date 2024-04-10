#include <bits/stdc++.h>
using namespace std;

int R;

vector<int> hv, use;
vector<char> ans;
int req[1000005];
int fr[1000005];

int main()
{
	int n; scanf("%d", &n);
	if (n >= 1389) R = 4;
	else if (n >= 232) R = 3;
	else if (n >= 199) R = 2;
	else if (n >= 2) R = 1;
	else
	{
		printf("a a\n");
		return 0;
	}
	for (int i = 0;i < R;i++) hv.push_back(0);
	hv.push_back(1);
	for (int i = R+1;;i++)
	{
		hv.push_back(hv.back()*i/(i-R));
		if (hv.back() > n) break;
	}
	for (int &u: hv) u--;
	for (int i = 0;i < 2*R;i++) hv[i] = 0;
	for (int i = 1;i <= n;i++) req[i] = 10000005;
	for (int i = 0;i <= n;i++) fr[i] = -1;
	for (int i = 1;i <= n;i++) for (unsigned j = 0;j < hv.size();j++)
		if (hv[j] <= i)
		{
			if (req[i-hv[j]]+j < req[i])
			{
				req[i] = req[i-hv[j]]+j;
				fr[i] = j;
			}
		} else break;
	/*int WORST = 0;
	for (int i = 0;i <= n;i++)
		if (req[i] == 10000005) printf("FAIL %d\n", i);
		else WORST = max(WORST, req[i]);
	printf("WORST %d\n", WORST);
	return 0;*/
	n--;
	for (int i = n;i;i -= hv[fr[i]]) use.push_back(fr[i]);
	for (unsigned i = 0;i < use.size();i++) for (int j = 0;j < R;j++) printf("%c", 'a'+i);
	for (int i = use.size()-1;i >= 0;i--) for (int j = 2*R;j < use[i];j++) printf("%c", 'a'+i);
	for (unsigned i = 0;i < use.size();i++) for (int j = 0;j < R;j++) printf("%c", 'a'+i);
	printf(" ");
	for (unsigned i = 0;i < use.size();i++) for (int j = 0;j < R;j++) printf("%c", 'a'+i);
	printf("\n");
	return 0;
}