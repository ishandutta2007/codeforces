#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"


using namespace std;
int n, m, k, ans, a[200009];
int main()
{

	cin >> n;

for(int i=1;i<=n;i++) cin >> a[i];
for(int i=1;i<=n-i+1;i++)
{
	if(i%2 ==1)
		swap(a[i], a[n-i+1]);
}

for(int i=1;i<=n;i++)
cout << a[i] << ' ';

	return 0;
}