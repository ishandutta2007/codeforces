#include "bits/stdc++.h"

using namespace std;

int main()
{
  int n, k;
	cin >> n >> k;
	vector <string> name(n);
	for(int i=0; i<n; i++)
	{
	  name[i] += 'A'+i/26;
		name[i] += 'a'+i%26;
  }
	for(int i=0; i<=n-k; i++)
	{
    string x;
		cin >> x;
		if(x == "NO")
		  name[i+k-1] = name[i];
	}
  for(int i=0; i<n; i++)
	  cout << name[i] << " ";
  return 0;
}