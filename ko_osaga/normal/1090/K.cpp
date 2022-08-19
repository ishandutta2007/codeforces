#include <stdio.h>
#include <vector>
#include <set>
#include <map>
using namespace std;

map<int, map<string, vector<int> > > chk;
char S[1001001],T[1001001];

int main()
{
	int N; scanf ("%d",&N); for (int g=1;g<=N;g++){
		scanf ("%s %s",S,T);
		int bit = 0;
		for (int i=0;T[i];i++){
			bit |= 1 << (T[i] - 'a');
		}
		int l = 0;
		while (S[l]) l++;

		while (l >= 1 && (bit & (1 << (S[l-1] - 'a')))) S[--l] = 0;
		chk[bit][S].push_back(g);
	}

	int ans = 0;
	for (auto &p : chk) ans += p.second.size();
	printf ("%d\n",ans);
	for (auto &p : chk) for (auto &q : p.second){
		printf ("%d",q.second.size());
		for (auto &i : q.second) printf (" %d",i);
		puts("");
	}

	return 0;
}