#include <bits/stdc++.h>
 
#define INF 1e9
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

int main(int argc, char** argv)
{
	int n, S, cnt = 0;
	cin >> n >> S;

	cnt = S / n;

	if(S % n != 0)
		++cnt;

	cout << cnt << endl;

    return 0;
}