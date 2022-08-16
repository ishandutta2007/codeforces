#include <bits/stdc++.h>

#define icin(x) scanf("%d",&x)
#define lcin(x) scanf("%lld",&x)
#define pb push_back
#define LL long long
#define F first
#define S second
#define VPI vector< pair<int,int> >
#define VVI vector< vector<int> > 
#define BC(x) __builtin_popcount(x)

using namespace std;




int main()
{
	int n;
	icin(n);
	vector<int> ar(n);
	vector<int> next(n,-1);
	vector<int> done(n,0);
	set< int > s;
	map<int,int> m;
	for(int i=0; i<n ;i++)
	{
		icin(ar[i]);
		m[ar[i]] = i; 
		auto it = s.upper_bound(ar[i]);
		if (it == s.begin() || (s.size() == 0));
		else {
			it--;

//			cerr << *it << "YO" << i << endl;
			int pos = m[*it];
//			cerr << pos << endl;
			next[pos] = i;
			s.erase(*it);
		}

		s.insert(ar[i]);
	}

	// for (int i=0; i<n; i++)
	// 	cerr << next[i] << " ";
	// cerr << endl;

	for (int i=0; i<n; i++){

		if(done[i] == 0) {
			int pos = i;
			while (pos != -1) {
				//assert(pos != done[pos]);
				done[pos] = 1;
				printf("%d ", ar[pos]);
				pos = next[pos];	
			}
			printf("\n");
		}
	}

	return 0;
}