#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif	


	int n, total_passengers, entering_passengers, exiting_passengers,max_passengers = 0;
	total_passengers = 0;
	entering_passengers = 0;
	exiting_passengers = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> exiting_passengers;
		total_passengers = total_passengers- exiting_passengers;
		cin >> entering_passengers;
		total_passengers = total_passengers + entering_passengers;
		max_passengers = max (max_passengers,total_passengers);
	}
	cout << max_passengers;
}